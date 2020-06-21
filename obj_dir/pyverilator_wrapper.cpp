#include <cstddef>
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vi2s.h"
    
// pyverilator defined values
// first declare variables as extern
extern const char* _pyverilator_module_name;
extern const uint32_t _pyverilator_num_inputs;
extern const char* _pyverilator_inputs[];
extern const uint32_t _pyverilator_input_widths[];
extern const uint32_t _pyverilator_num_outputs;
extern const char* _pyverilator_outputs[];
extern const uint32_t _pyverilator_output_widths[];
extern const uint32_t _pyverilator_num_internal_signals;
extern const char* _pyverilator_internal_signals[];
extern const uint32_t _pyverilator_internal_signal_widths[];
extern const uint32_t _pyverilator_num_rules;
extern const char* _pyverilator_rules[];
extern const char* _pyverilator_json_data;
// now initialize the variables
const char* _pyverilator_module_name = "Vi2s";
const uint32_t _pyverilator_num_inputs = 7;
const char* _pyverilator_inputs[] = {"sync__02Eclk","i2s_decoder__02Eclk","in","rst","sck","ws","sd"};
const uint32_t _pyverilator_input_widths[] = {1,1,1,1,1,1,1};

const uint32_t _pyverilator_num_outputs = 4;
const char* _pyverilator_outputs[] = {"sync_out","sample_clk","left_channel","right_channel"};
const uint32_t _pyverilator_output_widths[] = {1,1,16,16};

const uint32_t _pyverilator_num_internal_signals = 0;
const char* _pyverilator_internal_signals[] = {};
const uint32_t _pyverilator_internal_signal_widths[] = {};

const char* _pyverilator_json_data = "null";

// this is required by verilator for verilog designs using $time
// main_time is incremented in eval
double main_time = 0;
    
double sc_time_stamp() {
return main_time;
}
// function definitions
// helper functions for basic verilator tasks
extern "C" { //Open an extern C closed in the footer
Vi2s* construct() {
    Verilated::commandArgs(0, (const char**) nullptr);
    Verilated::traceEverOn(true);
    Vi2s* top = new Vi2s();
    return top;
}
int eval(Vi2s* top) {
    top->eval();
    main_time++;
    return 0;
}
int destruct(Vi2s* top) {
    if (top != nullptr) {
        delete top;
        top = nullptr;
    }
    return 0;
}
VerilatedVcdC* start_vcd_trace(Vi2s* top, const char* filename) {
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open(filename);
    return tfp;
}
int add_to_vcd_trace(VerilatedVcdC* tfp, int time) {
    tfp->dump(time);
    return 0;
}
int flush_vcd_trace(VerilatedVcdC* tfp) {
    tfp->flush();
    return 0;
}
int stop_vcd_trace(VerilatedVcdC* tfp) {
    tfp->close();
    return 0;
}
uint32_t get_sync_out(Vi2s* top){return top->sync_out;}
uint32_t get_sample_clk(Vi2s* top){return top->sample_clk;}
uint32_t get_left_channel(Vi2s* top){return top->left_channel;}
uint32_t get_right_channel(Vi2s* top){return top->right_channel;}
uint32_t get_sync__02Eclk(Vi2s* top){return top->sync__02Eclk;}
uint32_t get_i2s_decoder__02Eclk(Vi2s* top){return top->i2s_decoder__02Eclk;}
uint32_t get_in(Vi2s* top){return top->in;}
uint32_t get_rst(Vi2s* top){return top->rst;}
uint32_t get_sck(Vi2s* top){return top->sck;}
uint32_t get_ws(Vi2s* top){return top->ws;}
uint32_t get_sd(Vi2s* top){return top->sd;}
int set_sync__02Eclk(Vi2s* top, uint32_t new_value){ top->sync__02Eclk = new_value; return 0;}
int set_i2s_decoder__02Eclk(Vi2s* top, uint32_t new_value){ top->i2s_decoder__02Eclk = new_value; return 0;}
int set_in(Vi2s* top, uint32_t new_value){ top->in = new_value; return 0;}
int set_rst(Vi2s* top, uint32_t new_value){ top->rst = new_value; return 0;}
int set_sck(Vi2s* top, uint32_t new_value){ top->sck = new_value; return 0;}
int set_ws(Vi2s* top, uint32_t new_value){ top->ws = new_value; return 0;}
int set_sd(Vi2s* top, uint32_t new_value){ top->sd = new_value; return 0;}
}