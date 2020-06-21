module testmac(input clk, input [15:0] in1,input [15:0] in2,input [15:0] in3,input [15:0] in4, input [15:0] c1,input [15:0] c2,input [15:0] c3,input [15:0] c4, output [15:0] out);
    reg [31:0] acc;
    always @(posedge clk) begin
        acc <= in1*c1 + in2*c2 + in3*c3 + in4*c4;
    end
    assign out = acc[31:16];
endmodule