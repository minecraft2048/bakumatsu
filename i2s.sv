`include "basic_bits.sv"

module i2s_decoder (
    input clk,
    input sck,
    input ws,
    input sd,
    output reg [15:0] left_channel,
    output reg [15:0] right_channel,
    output sample_clk
    );
    
    reg [15:0] buffer;
    reg [3:0] counter;
    wire sck_p;
    wire sck_n;
    wire ws_p;
    wire ws_n;
    reg wsd;
    reg wsd1;
    wire wsp;

    edge_detect u_edge_detect_sck(
    	.clk    (clk    ),
        .rst    (0    ),
        .signal (sck ),
        .p_edge (sck_p ),
        .n_edge (sck_n) 
    );

    always @(posedge clk) begin
        if (sck_p) begin
            wsd <= ws;
        end
    end

    always @(posedge clk) begin
        if (sck_p) begin
            wsd1 <= wsd;
        end
    end

    assign wsp = wsd ^ wsd1;
    
    always @(posedge clk) begin
        if (sck_n) begin
            if (wsp) begin
                counter = 4'd15;
            end
            else if (counter != 0) begin
                counter = counter - 1;
            end 
        end
    end

    always @(posedge clk) begin
        if (sck_p) begin
            buffer[counter] <= sd;
        end
    end

    always @(posedge clk) begin
        if (sck_p) begin
            if ( wsp & ~wsd ) begin
                right_channel <= buffer;
            end else if (wsp & wsd) begin
                left_channel <= buffer;
            end 
        end
    end

    assign sample_clk = wsp & ~wsd;

endmodule