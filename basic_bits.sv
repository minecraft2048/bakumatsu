`ifndef BASIC_BITS_SV
`define BASIC_BITS_SV

module sync (
    input clk,
    input in,
    input rst,
    output reg sync_out
);
    
    reg intermediate;

    initial begin
        intermediate = 0;
        sync_out = 0;
    end

    always @(posedge clk) begin
        if ( rst ) begin
            intermediate <= 0;
        end else begin
            intermediate <= in;
        end
    end

    always @(posedge clk) begin
        if ( rst ) begin
            sync_out <= 0;
        end else begin
            sync_out <= intermediate;
        end
    end

endmodule

module edge_detect (
    input clk,
    input rst,
    input signal,
    output reg p_edge,
    output reg n_edge
);
    reg [1:0] ff;

    initial begin
        ff = 2'b00;
    end

    always @(posedge clk) begin
        if ( rst ) begin
            ff = 2'b00;
        end else begin
            ff = {ff[0],signal};

        end
    end

    always @(*) begin
        if (ff == 2'b01 ) begin
            p_edge = 1;
            n_edge = 0;
        end else if (ff == 2'b10 ) begin
            p_edge = 0;
            n_edge = 1;
        end else begin
            p_edge = 0;
            n_edge = 0;
        end
    end


endmodule
`endif