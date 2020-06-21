`include "uart_tx.sv"
`default_nettype none
`timescale 1 ns/10 ps

module tb;

    reg clk;
    wire out_test;
    reg uart_clk;
    reg [2:0] clk_div_reg;
    reg tx_interval_timer;
    reg [2:0] tx_interval_timer_ctr;


    uart_tx u_uart_tx(
    	.clk         (clk         ),
        .uart_clk_en (uart_clk ),
        .data        (8'h41        ),
        .start_tx    (tx_interval_timer    ),
        .rst         (0         ),
        .uart_out    (out_test    ),
        .ready ()
    );
    

    initial begin
        clk = 0;
        clk_div_reg = 0;
        uart_clk = 0;
        tx_interval_timer_ctr = 0;
        tx_interval_timer = 0;
        $dumpfile ("test.vcd");
        $dumpvars;
    end
/*
    always @(posedge clk) begin
        tx_interval_timer_ctr = tx_interval_timer_ctr + 1;
        if (tx_interval_timer_ctr == 3) begin
            tx_interval_timer = 1;
        end else if (tx_interval_timer_ctr == 4) begin
            tx_interval_timer = 0;
            tx_interval_timer_ctr = 0;
        end
    end
*/
    always @(posedge clk) begin
        clk_div_reg = clk_div_reg + 1;
        if (clk_div_reg == 2) begin
            uart_clk = 1;
        end else if (clk_div_reg == 3) begin
            uart_clk = 0;
            clk_div_reg = 0;
        end
    end

    always
        #1 clk = ~clk;

    initial begin
        #9 tx_interval_timer = 1;
        #2 tx_interval_timer = 0;
        #120 $finish;
    end

endmodule