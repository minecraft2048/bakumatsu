// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


//======================

void Vtop::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback(&Vtop::traceInit, &Vtop::traceFull, &Vtop::traceChg, this);
}
void Vtop::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    Vtop* t = (Vtop*)userthis;
    Vtop__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vcdp->scopeEscape(' ');
    t->traceInitThis(vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void Vtop::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vtop* t = (Vtop*)userthis;
    Vtop__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    t->traceFullThis(vlSymsp, vcdp, code);
}

//======================


void Vtop::traceInitThis(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name());  // Setup signal names
    // Body
    {
        vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void Vtop::traceFullThis(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vtop::traceInitThis__1(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->declBit(c+1,"clk", false,-1);
        vcdp->declBit(c+9,"sample_clk", false,-1);
        vcdp->declBus(c+17,"alpha", false,-1, 15,0);
        vcdp->declBus(c+25,"signal_in", false,-1, 15,0);
        vcdp->declBus(c+33,"filtered", false,-1, 15,0);
        vcdp->declBit(c+41,"ema_filter clk", false,-1);
        vcdp->declBit(c+49,"ema_filter sample_clk", false,-1);
        vcdp->declBus(c+57,"ema_filter alpha", false,-1, 15,0);
        vcdp->declBus(c+65,"ema_filter signal_in", false,-1, 15,0);
        vcdp->declBus(c+73,"ema_filter filtered", false,-1, 15,0);
        vcdp->declBus(c+81,"ema_filter state", false,-1, 31,0);
        vcdp->declBus(c+89,"ema_filter state_trunc", false,-1, 15,0);
    }
}

void Vtop::traceFullThis__1(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->fullBit(c+1,(vlTOPp->clk));
        vcdp->fullBit(c+9,(vlTOPp->sample_clk));
        vcdp->fullBus(c+17,(vlTOPp->alpha),16);
        vcdp->fullBus(c+25,(vlTOPp->signal_in),16);
        vcdp->fullBus(c+33,(vlTOPp->filtered),16);
        vcdp->fullBit(c+41,(vlTOPp->ema_filter__DOT__clk));
        vcdp->fullBit(c+49,(vlTOPp->ema_filter__DOT__sample_clk));
        vcdp->fullBus(c+57,(vlTOPp->ema_filter__DOT__alpha),16);
        vcdp->fullBus(c+65,(vlTOPp->ema_filter__DOT__signal_in),16);
        vcdp->fullBus(c+73,(vlTOPp->ema_filter__DOT__filtered),16);
        vcdp->fullBus(c+81,(vlTOPp->ema_filter__DOT__state),32);
        vcdp->fullBus(c+89,(vlTOPp->ema_filter__DOT__state_trunc),16);
    }
}
