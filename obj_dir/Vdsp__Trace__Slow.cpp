// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vdsp__Syms.h"


//======================

void Vdsp::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback(&Vdsp::traceInit, &Vdsp::traceFull, &Vdsp::traceChg, this);
}
void Vdsp::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    Vdsp* t = (Vdsp*)userthis;
    Vdsp__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vcdp->scopeEscape(' ');
    t->traceInitThis(vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void Vdsp::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vdsp* t = (Vdsp*)userthis;
    Vdsp__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    t->traceFullThis(vlSymsp, vcdp, code);
}

//======================


void Vdsp::traceInitThis(Vdsp__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vdsp* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name());  // Setup signal names
    // Body
    {
        vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void Vdsp::traceFullThis(Vdsp__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vdsp* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vdsp::traceInitThis__1(Vdsp__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vdsp* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->declBit(c+129,"sync.clk", false,-1);
        vcdp->declBit(c+137,"sync.in", false,-1);
        vcdp->declBit(c+145,"rst", false,-1);
        vcdp->declBit(c+153,"sync_out", false,-1);
        vcdp->declBit(c+161,"dds.clk", false,-1);
        vcdp->declBit(c+169,"dds.en", false,-1);
        vcdp->declBus(c+177,"freq", false,-1, 31,0);
        vcdp->declBus(c+185,"phase", false,-1, 31,0);
        vcdp->declBus(c+193,"dds.signal", false,-1, 15,0);
        vcdp->declBit(c+201,"dsdac.clk", false,-1);
        vcdp->declBit(c+209,"dsdac.en", false,-1);
        vcdp->declBus(c+217,"dsdac.signal", false,-1, 15,0);
        vcdp->declBit(c+225,"dsdac.bitstream", false,-1);
        vcdp->declBit(c+233,"pwmdac.clk", false,-1);
        vcdp->declBus(c+241,"pwmdac.signal", false,-1, 15,0);
        vcdp->declBit(c+249,"pwmdac.bitstream", false,-1);
        vcdp->declBit(c+257,"lfsr.clk", false,-1);
        vcdp->declBit(c+265,"lfsr.en", false,-1);
        vcdp->declBus(c+273,"random_num", false,-1, 23,0);
        vcdp->declBit(c+281,"mac4.clk", false,-1);
        vcdp->declBit(c+289,"mac4.en", false,-1);
        vcdp->declBus(c+297,"mac4.in", false,-1, 31,0);
        vcdp->declBus(c+305,"a0", false,-1, 15,0);
        vcdp->declBus(c+313,"c0", false,-1, 15,0);
        vcdp->declBus(c+321,"a1", false,-1, 15,0);
        vcdp->declBus(c+329,"c1", false,-1, 15,0);
        vcdp->declBus(c+337,"a2", false,-1, 15,0);
        vcdp->declBus(c+345,"c2", false,-1, 15,0);
        vcdp->declBus(c+353,"a3", false,-1, 15,0);
        vcdp->declBus(c+361,"c3", false,-1, 15,0);
        vcdp->declBus(c+369,"result", false,-1, 31,0);
        vcdp->declBit(c+377,"i2s_decoder.clk", false,-1);
        vcdp->declBit(c+385,"sck", false,-1);
        vcdp->declBit(c+393,"ws", false,-1);
        vcdp->declBit(c+401,"sd", false,-1);
        vcdp->declBus(c+409,"left_channel", false,-1, 15,0);
        vcdp->declBus(c+417,"right_channel", false,-1, 15,0);
        vcdp->declBit(c+425,"sample_clk", false,-1);
        vcdp->declBit(c+129,"sync clk", false,-1);
        vcdp->declBit(c+137,"sync in", false,-1);
        vcdp->declBit(c+145,"sync rst", false,-1);
        vcdp->declBit(c+153,"sync sync_out", false,-1);
        vcdp->declBit(c+25,"sync intermediate", false,-1);
        vcdp->declBit(c+161,"dds clk", false,-1);
        vcdp->declBit(c+169,"dds en", false,-1);
        vcdp->declBus(c+177,"dds freq", false,-1, 31,0);
        vcdp->declBus(c+185,"dds phase", false,-1, 31,0);
        vcdp->declBus(c+193,"dds signal", false,-1, 15,0);
        vcdp->declBus(c+441,"dds lut_size", false,-1, 31,0);
        vcdp->declBus(c+449,"dds accumulator_size", false,-1, 31,0);
        vcdp->declBus(c+97,"dds phase_accumulator_1", false,-1, 31,0);
        vcdp->declBus(c+105,"dds phase_accumulator_out", false,-1, 31,0);
        vcdp->declBit(c+201,"dsdac clk", false,-1);
        vcdp->declBit(c+209,"dsdac en", false,-1);
        vcdp->declBus(c+217,"dsdac signal", false,-1, 15,0);
        vcdp->declBit(c+225,"dsdac bitstream", false,-1);
        vcdp->declBus(c+81,"dsdac signal_register", false,-1, 16,0);
        vcdp->declBus(c+89,"dsdac ddc", false,-1, 16,0);
        vcdp->declBit(c+233,"pwmdac clk", false,-1);
        vcdp->declBus(c+241,"pwmdac signal", false,-1, 15,0);
        vcdp->declBit(c+249,"pwmdac bitstream", false,-1);
        vcdp->declBus(c+1,"pwmdac signal_register", false,-1, 15,0);
        vcdp->declBit(c+257,"lfsr clk", false,-1);
        vcdp->declBit(c+265,"lfsr en", false,-1);
        vcdp->declBus(c+273,"lfsr random_num", false,-1, 23,0);
        vcdp->declBit(c+433,"lfsr bit_insert", false,-1);
        vcdp->declBit(c+281,"mac4 clk", false,-1);
        vcdp->declBit(c+289,"mac4 en", false,-1);
        vcdp->declBus(c+297,"mac4 in", false,-1, 31,0);
        vcdp->declBus(c+305,"mac4 a0", false,-1, 15,0);
        vcdp->declBus(c+313,"mac4 c0", false,-1, 15,0);
        vcdp->declBus(c+321,"mac4 a1", false,-1, 15,0);
        vcdp->declBus(c+329,"mac4 c1", false,-1, 15,0);
        vcdp->declBus(c+337,"mac4 a2", false,-1, 15,0);
        vcdp->declBus(c+345,"mac4 c2", false,-1, 15,0);
        vcdp->declBus(c+353,"mac4 a3", false,-1, 15,0);
        vcdp->declBus(c+361,"mac4 c3", false,-1, 15,0);
        vcdp->declBus(c+369,"mac4 result", false,-1, 31,0);
        vcdp->declBit(c+9,"mac4 check", false,-1);
        vcdp->declBus(c+17,"mac4 out", false,-1, 31,0);
        vcdp->declBit(c+377,"i2s_decoder clk", false,-1);
        vcdp->declBit(c+385,"i2s_decoder sck", false,-1);
        vcdp->declBit(c+393,"i2s_decoder ws", false,-1);
        vcdp->declBit(c+401,"i2s_decoder sd", false,-1);
        vcdp->declBus(c+409,"i2s_decoder left_channel", false,-1, 15,0);
        vcdp->declBus(c+417,"i2s_decoder right_channel", false,-1, 15,0);
        vcdp->declBit(c+425,"i2s_decoder sample_clk", false,-1);
        vcdp->declBus(c+113,"i2s_decoder buffer", false,-1, 15,0);
        vcdp->declBus(c+121,"i2s_decoder counter", false,-1, 3,0);
        vcdp->declBit(c+33,"i2s_decoder sck_p", false,-1);
        vcdp->declBit(c+41,"i2s_decoder sck_n", false,-1);
        vcdp->declBit(c+49,"i2s_decoder ws_p", false,-1);
        vcdp->declBit(c+57,"i2s_decoder ws_n", false,-1);
        vcdp->declBit(c+377,"i2s_decoder u_edge_detect_sck clk", false,-1);
        vcdp->declBit(c+457,"i2s_decoder u_edge_detect_sck rst", false,-1);
        vcdp->declBit(c+385,"i2s_decoder u_edge_detect_sck signal", false,-1);
        vcdp->declBit(c+33,"i2s_decoder u_edge_detect_sck p_edge", false,-1);
        vcdp->declBit(c+41,"i2s_decoder u_edge_detect_sck n_edge", false,-1);
        vcdp->declBus(c+65,"i2s_decoder u_edge_detect_sck ff", false,-1, 1,0);
        vcdp->declBit(c+377,"i2s_decoder u_edge_detect_ws clk", false,-1);
        vcdp->declBit(c+457,"i2s_decoder u_edge_detect_ws rst", false,-1);
        vcdp->declBit(c+393,"i2s_decoder u_edge_detect_ws signal", false,-1);
        vcdp->declBit(c+49,"i2s_decoder u_edge_detect_ws p_edge", false,-1);
        vcdp->declBit(c+57,"i2s_decoder u_edge_detect_ws n_edge", false,-1);
        vcdp->declBus(c+73,"i2s_decoder u_edge_detect_ws ff", false,-1, 1,0);
    }
}

void Vdsp::traceFullThis__1(Vdsp__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vdsp* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->fullBus(c+1,(vlTOPp->pwmdac__DOT__signal_register),16);
        vcdp->fullBit(c+9,(vlTOPp->mac4__DOT__check));
        vcdp->fullBus(c+17,(vlTOPp->mac4__DOT__out),32);
        vcdp->fullBit(c+25,(vlTOPp->sync__DOT__intermediate));
        vcdp->fullBit(c+33,(vlTOPp->i2s_decoder__DOT__sck_p));
        vcdp->fullBit(c+41,(vlTOPp->i2s_decoder__DOT__sck_n));
        vcdp->fullBit(c+49,(vlTOPp->i2s_decoder__DOT__ws_p));
        vcdp->fullBit(c+57,(vlTOPp->i2s_decoder__DOT__ws_n));
        vcdp->fullBus(c+65,(vlTOPp->i2s_decoder__DOT__u_edge_detect_sck__DOT__ff),2);
        vcdp->fullBus(c+73,(vlTOPp->i2s_decoder__DOT__u_edge_detect_ws__DOT__ff),2);
        vcdp->fullBus(c+81,(vlTOPp->dsdac__DOT__signal_register),17);
        vcdp->fullBus(c+89,(vlTOPp->dsdac__DOT__ddc),17);
        vcdp->fullBus(c+97,(vlTOPp->dds__DOT__phase_accumulator_1),32);
        vcdp->fullBus(c+105,(vlTOPp->dds__DOT__phase_accumulator_out),32);
        vcdp->fullBus(c+113,(vlTOPp->i2s_decoder__DOT__buffer),16);
        vcdp->fullBus(c+121,(vlTOPp->i2s_decoder__DOT__counter),4);
        vcdp->fullBit(c+129,(vlTOPp->sync__02Eclk));
        vcdp->fullBit(c+137,(vlTOPp->sync__02Ein));
        vcdp->fullBit(c+145,(vlTOPp->rst));
        vcdp->fullBit(c+153,(vlTOPp->sync_out));
        vcdp->fullBit(c+161,(vlTOPp->dds__02Eclk));
        vcdp->fullBit(c+169,(vlTOPp->dds__02Een));
        vcdp->fullBus(c+177,(vlTOPp->freq),32);
        vcdp->fullBus(c+185,(vlTOPp->phase),32);
        vcdp->fullBus(c+193,(vlTOPp->dds__02Esignal),16);
        vcdp->fullBit(c+201,(vlTOPp->dsdac__02Eclk));
        vcdp->fullBit(c+209,(vlTOPp->dsdac__02Een));
        vcdp->fullBus(c+217,(vlTOPp->dsdac__02Esignal),16);
        vcdp->fullBit(c+225,(vlTOPp->dsdac__02Ebitstream));
        vcdp->fullBit(c+233,(vlTOPp->pwmdac__02Eclk));
        vcdp->fullBus(c+241,(vlTOPp->pwmdac__02Esignal),16);
        vcdp->fullBit(c+249,(vlTOPp->pwmdac__02Ebitstream));
        vcdp->fullBit(c+257,(vlTOPp->lfsr__02Eclk));
        vcdp->fullBit(c+265,(vlTOPp->lfsr__02Een));
        vcdp->fullBus(c+273,(vlTOPp->random_num),24);
        vcdp->fullBit(c+281,(vlTOPp->mac4__02Eclk));
        vcdp->fullBit(c+289,(vlTOPp->mac4__02Een));
        vcdp->fullBus(c+297,(vlTOPp->mac4__02Ein),32);
        vcdp->fullBus(c+305,(vlTOPp->a0),16);
        vcdp->fullBus(c+313,(vlTOPp->c0),16);
        vcdp->fullBus(c+321,(vlTOPp->a1),16);
        vcdp->fullBus(c+329,(vlTOPp->c1),16);
        vcdp->fullBus(c+337,(vlTOPp->a2),16);
        vcdp->fullBus(c+345,(vlTOPp->c2),16);
        vcdp->fullBus(c+353,(vlTOPp->a3),16);
        vcdp->fullBus(c+361,(vlTOPp->c3),16);
        vcdp->fullBus(c+369,(vlTOPp->result),32);
        vcdp->fullBit(c+377,(vlTOPp->i2s_decoder__02Eclk));
        vcdp->fullBit(c+385,(vlTOPp->sck));
        vcdp->fullBit(c+393,(vlTOPp->ws));
        vcdp->fullBit(c+401,(vlTOPp->sd));
        vcdp->fullBus(c+409,(vlTOPp->left_channel),16);
        vcdp->fullBus(c+417,(vlTOPp->right_channel),16);
        vcdp->fullBit(c+425,(vlTOPp->sample_clk));
        vcdp->fullBit(c+433,((1U & (((vlTOPp->random_num 
                                      ^ (vlTOPp->random_num 
                                         >> 1U)) ^ 
                                     (vlTOPp->random_num 
                                      >> 2U)) ^ (vlTOPp->random_num 
                                                 >> 7U)))));
        vcdp->fullBus(c+441,(9U),32);
        vcdp->fullBus(c+449,(0x20U),32);
        vcdp->fullBit(c+457,(0U));
    }
}
