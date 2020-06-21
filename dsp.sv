`default_nettype none

`ifndef DSP_SV
`define DSP_SV

module dds(input clk, input en, input [accumulator_size-1:0] freq,input [accumulator_size-1:0] phase, output reg [15:0] signal);
    localparam lut_size = 9;
    localparam accumulator_size = 32;
    reg [accumulator_size-1:0] phase_accumulator_1;
     reg [accumulator_size-1:0] phase_accumulator_out;
    reg [15:0] sine_table [0:2**lut_size-1];

    initial begin
        $readmemh("sine_lut.mem",sine_table);
    end

    always @(posedge clk) begin
        if (en) begin
            phase_accumulator_1 <= phase_accumulator_1 + freq;
            phase_accumulator_out <=phase_accumulator_1 + phase;
            signal <= sine_table[phase_accumulator_out[accumulator_size-1:(accumulator_size-1)-(lut_size-1)]];
        end
        else begin
            signal <= 0;
        end
    end
/*
    always @(posedge clk) begin
        signal1 <= sine_table[phase_accumulator_1[9:2]];
        //signal2 <= sine_table[phase_accumulator_2[9:2]];
    end
*/
endmodule

module dsdac(input clk, input en, input signed [15:0] signal, output reg bitstream);
    reg signed [16:0] signal_register;
    reg signed [16:0] ddc;

    initial begin
        signal_register = 0;
        ddc = 0;
    end

    always @(posedge clk) begin
        if (en) begin
            signal_register = signal_register + signal - ddc;    
        end
    end
    
   always @(*) begin
        if ( signal_register > 0 ) begin
            bitstream = 1;
            ddc = 32767;
        end else begin
            bitstream = 0;
            ddc = -32768;
        end
    end

endmodule

module pwmdac(input clk, input signed [15:0] signal, output reg bitstream);
    reg [15:0] signal_register;

    initial begin
        signal_register = 0;
    end

    always @(posedge clk) begin
        signal_register = signal_register + 1;
        if (signal_register >= signal) begin
            bitstream = 1;
        end else begin 
            bitstream = 0;
        end
    end
endmodule

module lfsr(input clk, input en, output reg [23:0] random_num);

    reg bit_insert;

    initial begin
        random_num = 24'habcdef;
    end

    always @(posedge clk) begin
        if (en) begin
            random_num = {bit_insert,random_num[23:1]};
        end
    end
    //https://en.wikipedia.org/wiki/Linear-feedback_shift_register#Some_polynomials_for_maximal_LFSRs
    //Polynomial for 24 bit LFSR x^24+x^23+x^22+x^16+1
    always @(*) begin
        bit_insert = ((random_num[0] ^ random_num[1]) ^ random_num[2]) ^ random_num[7];
    end

endmodule

module mac4(input clk, 
            input en, 
            input signed [31:0] in, 
            input signed [15:0] a0, 
            input signed [15:0] c0,
            input signed [15:0] a1, 
            input signed [15:0] c1,
            input signed [15:0] a2, 
            input signed [15:0] c2,
            input signed [15:0] a3, 
            input signed [15:0] c3,
            output reg signed [31:0] result);

        reg check;
        reg signed [31:0] out;

        always @(*) begin
            {check,out} = in + a0*c0 + a1*c1 + a2*c2 + a3*c3;
        end

        always @(*) begin
            if ({check,out[31]} == 2'b01) begin
                result = 32'h7fffffff;
            end
            else if ({check,out[31]} == 2'b10) begin
                result = 32'h80000000;
            end
            else begin
                result = out;
            end
        end
        
endmodule

module vu_filter (
    input clk,
    input sample_clk_en,
    input signed [15:0] in,
    output reg signed [15:0] out
);
    
    localparam a1 = 16'sh1234;
    localparam a2 = 16'sh5678;

    //Q1.15 here
    reg signed [15:0] x1;
    reg signed [15:0] y1;
    reg signed [15:0] y2;

    //Q17.15 here
    reg signed [31:0] intermediate;

    always @(posedge clk) begin
        x1 <= in; //do sign extension?
        y1 <= intermediate[31:16]; //truncate 32 bits to 16 bits
        y2 <= y1;
    end

    always_comb begin
        intermediate = (in + x1) - (a1*y1 + a2*y2);
        out = y1;
    end

endmodule

module ema_filter (
    input clk,
    input sample_clk,
    input signed [15:0] alpha,
    input signed [15:0] signal_in,
    output reg signed [15:0] filtered
);
    
    reg signed [31:0] state; //Q1.31
    reg signed [15:0] state_trunc; //Q1.15

/* verilator lint_off WIDTH */
    always @(posedge clk) begin
        if (sample_clk) begin
            state <= state + (alpha*(signal_in-state_trunc));
        end
    end

    always_comb begin
        state_trunc = state[31:16];
        filtered = state_trunc;
    end

endmodule
/* verilator lint_on WIDTH */
module log10_filter (
    input clk,
    input sample_clk,
    input [14:0] signal,
    output reg [5:0] out_log
);
  reg [5:0] log_table [0:2**15-1]; //warning!!! memory intensive

    initial begin
        $readmemb("log_lut.mem",log_table);
    end

    always @(posedge clk) begin
        if (sample_clk) begin
            out_log <= log_table[signal];
        end
    end

endmodule

module abs_filter (
    input clk,
    input signed [15:0] signal,
    output reg [14:0] out_abs
);

    reg [15:0] out_abs_int;
    always @(posedge clk) begin
        if ( signal < 0 ) begin
            out_abs_int = -signal;
        end else begin
            out_abs_int = signal;
        end
    end

    assign out_abs = out_abs_int[14:0];
    
endmodule

`endif