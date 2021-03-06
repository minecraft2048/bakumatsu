module testmac(input clk, input [15:0] a, input [15:0] b, output [31:0] out);
    reg [31:0] acc;
    always @(posedge clk) begin
        acc <= acc + a * b;
    end
    assign out = acc;
endmodule