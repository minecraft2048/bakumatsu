// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vi2s__Syms.h"


//======================

void Vi2s::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback(&Vi2s::traceInit, &Vi2s::traceFull, &Vi2s::traceChg, this);
}
void Vi2s::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    Vi2s* t = (Vi2s*)userthis;
    Vi2s__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vcdp->scopeEscape(' ');
    t->traceInitThis(vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void Vi2s::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vi2s* t = (Vi2s*)userthis;
    Vi2s__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    t->traceFullThis(vlSymsp, vcdp, code);
}

//======================


void Vi2s::traceInitThis(Vi2s__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vi2s* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name());  // Setup signal names
    // Body
    {
        vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void Vi2s::traceFullThis(Vi2s__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vi2s* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vi2s::traceInitThis__1(Vi2s__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vi2s* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->declBit(c+73,"sync.clk", false,-1);
        vcdp->declBit(c+81,"in", false,-1);
        vcdp->declBit(c+89,"rst", false,-1);
        vcdp->declBit(c+97,"sync_out", false,-1);
        vcdp->declBit(c+105,"i2s_decoder.clk", false,-1);
        vcdp->declBit(c+113,"sck", false,-1);
        vcdp->declBit(c+121,"ws", false,-1);
        vcdp->declBit(c+129,"sd", false,-1);
        vcdp->declBus(c+137,"left_channel", false,-1, 15,0);
        vcdp->declBus(c+145,"right_channel", false,-1, 15,0);
        vcdp->declBit(c+153,"sample_clk", false,-1);
        vcdp->declBit(c+73,"sync clk", false,-1);
        vcdp->declBit(c+81,"sync in", false,-1);
        vcdp->declBit(c+89,"sync rst", false,-1);
        vcdp->declBit(c+97,"sync sync_out", false,-1);
        vcdp->declBit(c+1,"sync intermediate", false,-1);
        vcdp->declBit(c+105,"i2s_decoder clk", false,-1);
        vcdp->declBit(c+113,"i2s_decoder sck", false,-1);
        vcdp->declBit(c+121,"i2s_decoder ws", false,-1);
        vcdp->declBit(c+129,"i2s_decoder sd", false,-1);
        vcdp->declBus(c+137,"i2s_decoder left_channel", false,-1, 15,0);
        vcdp->declBus(c+145,"i2s_decoder right_channel", false,-1, 15,0);
        vcdp->declBit(c+153,"i2s_decoder sample_clk", false,-1);
        vcdp->declBus(c+57,"i2s_decoder buffer", false,-1, 15,0);
        vcdp->declBus(c+65,"i2s_decoder counter", false,-1, 3,0);
        vcdp->declBit(c+9,"i2s_decoder sck_p", false,-1);
        vcdp->declBit(c+17,"i2s_decoder sck_n", false,-1);
        vcdp->declBit(c+25,"i2s_decoder ws_p", false,-1);
        vcdp->declBit(c+33,"i2s_decoder ws_n", false,-1);
        vcdp->declBit(c+105,"i2s_decoder u_edge_detect_sck clk", false,-1);
        vcdp->declBit(c+161,"i2s_decoder u_edge_detect_sck rst", false,-1);
        vcdp->declBit(c+113,"i2s_decoder u_edge_detect_sck signal", false,-1);
        vcdp->declBit(c+9,"i2s_decoder u_edge_detect_sck p_edge", false,-1);
        vcdp->declBit(c+17,"i2s_decoder u_edge_detect_sck n_edge", false,-1);
        vcdp->declBus(c+41,"i2s_decoder u_edge_detect_sck ff", false,-1, 1,0);
        vcdp->declBit(c+105,"i2s_decoder u_edge_detect_ws clk", false,-1);
        vcdp->declBit(c+161,"i2s_decoder u_edge_detect_ws rst", false,-1);
        vcdp->declBit(c+121,"i2s_decoder u_edge_detect_ws signal", false,-1);
        vcdp->declBit(c+25,"i2s_decoder u_edge_detect_ws p_edge", false,-1);
        vcdp->declBit(c+33,"i2s_decoder u_edge_detect_ws n_edge", false,-1);
        vcdp->declBus(c+49,"i2s_decoder u_edge_detect_ws ff", false,-1, 1,0);
    }
}

void Vi2s::traceFullThis__1(Vi2s__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vi2s* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->fullBit(c+1,(vlTOPp->sync__DOT__intermediate));
        vcdp->fullBit(c+9,(vlTOPp->i2s_decoder__DOT__sck_p));
        vcdp->fullBit(c+17,(vlTOPp->i2s_decoder__DOT__sck_n));
        vcdp->fullBit(c+25,(vlTOPp->i2s_decoder__DOT__ws_p));
        vcdp->fullBit(c+33,(vlTOPp->i2s_decoder__DOT__ws_n));
        vcdp->fullBus(c+41,(vlTOPp->i2s_decoder__DOT__u_edge_detect_sck__DOT__ff),2);
        vcdp->fullBus(c+49,(vlTOPp->i2s_decoder__DOT__u_edge_detect_ws__DOT__ff),2);
        vcdp->fullBus(c+57,(vlTOPp->i2s_decoder__DOT__buffer),16);
        vcdp->fullBus(c+65,(vlTOPp->i2s_decoder__DOT__counter),4);
        vcdp->fullBit(c+73,(vlTOPp->sync__02Eclk));
        vcdp->fullBit(c+81,(vlTOPp->in));
        vcdp->fullBit(c+89,(vlTOPp->rst));
        vcdp->fullBit(c+97,(vlTOPp->sync_out));
        vcdp->fullBit(c+105,(vlTOPp->i2s_decoder__02Eclk));
        vcdp->fullBit(c+113,(vlTOPp->sck));
        vcdp->fullBit(c+121,(vlTOPp->ws));
        vcdp->fullBit(c+129,(vlTOPp->sd));
        vcdp->fullBus(c+137,(vlTOPp->left_channel),16);
        vcdp->fullBus(c+145,(vlTOPp->right_channel),16);
        vcdp->fullBit(c+153,(vlTOPp->sample_clk));
        vcdp->fullBit(c+161,(0U));
    }
}
