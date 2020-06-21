`include "dsp.sv"
`include "basic_bits.sv"
`include "i2s.sv"
`include "uart_tx.sv"

`default_nettype none

module tb_hw (
    input clk, 
    output out_test, 
    output reg uart_tx_out, 
    input uart_rx, 
    output reg rpi_tx, 
    input rpi_rx,
    input sck_in,
    input ws_in,
    input sd_in,
    output out_test2,
    output [7:0] led
);

    wire [15:0] test_sig;
    wire signed [23:0] white_noise;
    reg signed [15:0] dither_sig;

    reg int1;
    reg int2;
    reg int3;
    reg int4;



    reg tx_interval_timer;
    reg [23:0] tx_interval_timer_ctr;

    reg uart_clk;
    reg [10:0] uart_clk_ctr;



    dds u_dds_tb(
    	.clk     (clk     ),
        .en (1),
        .freq    (32'd157482    ),
        .phase   (32'd0   ),
        .signal (test_sig)
    );

    lfsr u_lfsr(
    	.clk        (clk        ),
        .en         (1         ),
        .random_num (white_noise )
    );
    
    
    dsdac u_dsdac_left(
    	.clk    (clk    ),
        .en (1),
        .signal (left_channel ),
        .bitstream (out_test)
    );

    dsdac u_dsdac_right(
    	.clk    (clk    ),
        .en (1),
        .signal (right_channel ),
        .bitstream (out_test2)
    );

    always @(*) begin
        dither_sig = test_sig;
    end

/*
    sync u_sync_1(
    	.clk      (clk      ),
        .in       (rpi_rx       ),
        .rst      (0      ),
        .sync_out (uart_tx )
    ); */


    always @(posedge clk) begin
        tx_interval_timer_ctr = tx_interval_timer_ctr + 1;
        if (tx_interval_timer_ctr == 12000000) begin
            tx_interval_timer = 1;
        end else if (tx_interval_timer_ctr == 12000001) begin
            tx_interval_timer = 0;
            tx_interval_timer_ctr = 0;
        end
    end


    always @(posedge clk) begin
        uart_clk_ctr = uart_clk_ctr + 1;
        if (uart_clk_ctr == 1250) begin
            uart_clk = 1;
        end else if (uart_clk_ctr == 1250+1) begin
            uart_clk = 0;
            uart_clk = 0;
        end
    end
/*
    uart_tx u_uart_tx(
        .clk         (clk         ),
        .uart_clk_en (uart_clk ),
        .data        (8'h41         ),
        .start_tx    (tx_interval_timer   ),
        .rst         (0         ),
        .uart_out    (uart_tx_out    ),
        .ready       ()
    ); */



    sync u_sync_2(
        .clk      (clk      ),
        .in       (uart_rx       ),
        .rst      (0      ),
        .sync_out (rpi_tx )
    );
    

    //I2S interfaces

    wire sck;
    wire ws;
    wire sd;


    sync u_sync_sck(
    	.clk      (clk      ),
        .in       (sck_in       ),
        .rst      (0      ),
        .sync_out (sck) 
    );

    sync u_sync_ws(
        .clk      (clk      ),
        .in       (ws_in       ),
        .rst      (0      ),
        .sync_out (ws )
    );
    
    sync u_sync_sd(
    	.clk      (clk      ),
        .in       (sd_in       ),
        .rst      (0      ),
        .sync_out (sd )
    );

    //I2S passthrough
    
    //assign sck_pass = sck;
    //assign ws_pass = ws;
    //assign sd_pass = sd;

    wire [15:0] right_channel;
    wire [15:0] left_channel;
    wire sample_clk;
    i2s_decoder u_i2s_decoder(
    	.clk           (clk           ),
        .sck           (sck           ),
        .ws            (ws            ),
        .sd            (sd            ),
        .left_channel  (left_channel  ),
        .right_channel (right_channel ),
        .sample_clk    ( sample_clk  )
    );
    
    wire [15:0] ema_filtered;
    ema_filter u_ema_filter(
    	.clk        (clk        ),
        .sample_clk (sample_clk ),
        .alpha      (10      ),
        .signal_in  (right_channel  ),
        .filtered   (ema_filtered   )
    );
    
    wire [14:0] abs_signal;
    abs_filter u_abs_filter(
    	.clk     (clk     ),
        .signal  (ema_filtered  ),
        .out_abs (abs_signal )
    );
    
    wire [5:0] log_signal;
    log10_filter u_log10_filter(
    	.clk        (clk        ),
        .sample_clk (1 ),
        .signal     (abs_signal     ),
        .out_log    (log_signal    )
    );
    
    //led bargraph

    reg [7:0] led1;
    reg [7:0] led_rev;

    always @(posedge clk) begin
        if ( log_signal <= 7 ) begin
            led1 <= 8'b0000_0001;
        end else if (log_signal > 7 && log_signal <= 13) begin
            led1 <= 8'b0000_0011;
        end else if (log_signal > 13 && log_signal <= 20) begin
            led1 <= 8'b0000_0111;
        end else if (log_signal > 20 && log_signal <= 26) begin
            led1 <= 8'b0000_1111;
        end else if (log_signal > 26 && log_signal <= 32) begin
            led1 <= 8'b0001_1111;
        end else if (log_signal > 32 && log_signal <= 39) begin
            led1 <= 8'b0011_1111;
        end else if (log_signal > 39 && log_signal < 46) begin
            led1 <= 8'b0111_1111;
        end else if (log_signal >= 46) begin
            led1 <= 8'b1111_1111;
        end
    end 

    assign led_rev = ~led1;
    assign led = {led_rev[0],led_rev[1],led_rev[2],led_rev[3],led_rev[4],led_rev[5],led_rev[6],led_rev[7]};

endmodule