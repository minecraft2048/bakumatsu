// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vi2s__Syms.h"


//======================

void Vi2s::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vi2s* t = (Vi2s*)userthis;
    Vi2s__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
        t->traceChgThis(vlSymsp, vcdp, code);
    }
}

//======================


void Vi2s::traceChgThis(Vi2s__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vi2s* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
                               | (vlTOPp->__Vm_traceActivity 
                                  >> 1U))))) {
            vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
                               | (vlTOPp->__Vm_traceActivity 
                                  >> 2U))))) {
            vlTOPp->traceChgThis__3(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((4U & vlTOPp->__Vm_traceActivity))) {
            vlTOPp->traceChgThis__4(vlSymsp, vcdp, code);
        }
        vlTOPp->traceChgThis__5(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vi2s::traceChgThis__2(Vi2s__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vi2s* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+1,(vlTOPp->sync__DOT__intermediate));
    }
}

void Vi2s::traceChgThis__3(Vi2s__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vi2s* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+9,(vlTOPp->i2s_decoder__DOT__sck_p));
        vcdp->chgBit(c+17,(vlTOPp->i2s_decoder__DOT__sck_n));
        vcdp->chgBit(c+25,(vlTOPp->i2s_decoder__DOT__ws_p));
        vcdp->chgBit(c+33,(vlTOPp->i2s_decoder__DOT__ws_n));
        vcdp->chgBus(c+41,(vlTOPp->i2s_decoder__DOT__u_edge_detect_sck__DOT__ff),2);
        vcdp->chgBus(c+49,(vlTOPp->i2s_decoder__DOT__u_edge_detect_ws__DOT__ff),2);
    }
}

void Vi2s::traceChgThis__4(Vi2s__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vi2s* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+57,(vlTOPp->i2s_decoder__DOT__buffer),16);
        vcdp->chgBus(c+65,(vlTOPp->i2s_decoder__DOT__counter),4);
    }
}

void Vi2s::traceChgThis__5(Vi2s__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vi2s* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+73,(vlTOPp->sync__02Eclk));
        vcdp->chgBit(c+81,(vlTOPp->in));
        vcdp->chgBit(c+89,(vlTOPp->rst));
        vcdp->chgBit(c+97,(vlTOPp->sync_out));
        vcdp->chgBit(c+105,(vlTOPp->i2s_decoder__02Eclk));
        vcdp->chgBit(c+113,(vlTOPp->sck));
        vcdp->chgBit(c+121,(vlTOPp->ws));
        vcdp->chgBit(c+129,(vlTOPp->sd));
        vcdp->chgBus(c+137,(vlTOPp->left_channel),16);
        vcdp->chgBus(c+145,(vlTOPp->right_channel),16);
        vcdp->chgBit(c+153,(vlTOPp->sample_clk));
    }
}
