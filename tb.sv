`include "dsp.sv"
`default_nettype none

module tb;

    reg clk;
    wire [15:0] test_sig_out;
    reg [15:0] test_sig;
    wire out_test;

    dds u_dds_tb(
    	.clk     (clk     ),
        .freq    (32'd157482    ),
        .phase   (32'd0   ),
        .signal1 (test_sig_out)
    );
     
    dsdac u_dsdac(
    	.clk    (clk    ),
        .en (1),
        .signal (test_sig ),
        .bitstream (out_test    )
    );
    
    initial begin
        clk = 0;
        test_sig = 0;
        $dumpfile ("test.vcd");
        $dumpvars;
    end

    always @(posedge clk) begin
        test_sig = test_sig_out;
    end

    always
        #1 clk = ~clk;

    initial begin
        #12000000 $finish;
    end

endmodule