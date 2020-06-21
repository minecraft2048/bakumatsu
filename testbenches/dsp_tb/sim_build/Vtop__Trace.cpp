// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


//======================

void Vtop::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vtop* t = (Vtop*)userthis;
    Vtop__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
        t->traceChgThis(vlSymsp, vcdp, code);
    }
}

//======================


void Vtop::traceChgThis(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vtop::traceChgThis__2(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+1,(vlTOPp->clk));
        vcdp->chgBit(c+9,(vlTOPp->sample_clk));
        vcdp->chgBus(c+17,(vlTOPp->alpha),16);
        vcdp->chgBus(c+25,(vlTOPp->signal_in),16);
        vcdp->chgBus(c+33,(vlTOPp->filtered),16);
        vcdp->chgBit(c+41,(vlTOPp->ema_filter__DOT__clk));
        vcdp->chgBit(c+49,(vlTOPp->ema_filter__DOT__sample_clk));
        vcdp->chgBus(c+57,(vlTOPp->ema_filter__DOT__alpha),16);
        vcdp->chgBus(c+65,(vlTOPp->ema_filter__DOT__signal_in),16);
        vcdp->chgBus(c+73,(vlTOPp->ema_filter__DOT__filtered),16);
        vcdp->chgBus(c+81,(vlTOPp->ema_filter__DOT__state),32);
        vcdp->chgBus(c+89,(vlTOPp->ema_filter__DOT__state_trunc),16);
    }
}
