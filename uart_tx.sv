`default_nettype none
`ifndef UART_TX_SV
`define UART_TX_SV

module uart_tx (
    input clk,
    input uart_clk_en,
    input [7:0] data,
    input start_tx,
    input rst,
    output reg uart_out,
    output reg ready

);
    

//State definitions and reset

reg [3:0] state;
reg [3:0] next_state;

localparam [3:0] UART_IDLE = 0;
localparam [3:0] UART_START_BIT = 1;
localparam [3:0] UART_START_TX = 2;
localparam [3:0] UART_STOP_BIT = 10;

reg [7:0] buffer;


initial begin
    buffer = 0;
    state = UART_IDLE;
    next_state = UART_IDLE;
    uart_out = 1;
end


always @(posedge clk) begin
    if(uart_clk_en) begin
        state <= next_state;
    end
end

always @(posedge clk) begin
    if ( state == UART_IDLE ) begin
        if (start_tx) begin
            buffer <= data;
            next_state <= UART_START_BIT;
            ready <= 0;
        end
        else begin
            ready <= 1;
            uart_out <= 1;
        end
    end
end

always @(posedge clk) begin
    if (state == UART_START_BIT) begin
        uart_out <= 0;
        next_state <= UART_START_TX;
    end else if (state >= UART_START_TX && state < UART_STOP_BIT) begin
        uart_out <= buffer[state-2];
        next_state <= state + 1;
    end else if (state == UART_STOP_BIT) begin
        uart_out <= 1;
        next_state <= UART_IDLE;
    end else if (state > UART_STOP_BIT) begin
        next_state <= UART_IDLE;
    end
end

endmodule



`endif