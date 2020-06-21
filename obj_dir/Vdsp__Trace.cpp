// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vdsp__Syms.h"


//======================

void Vdsp::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vdsp* t = (Vdsp*)userthis;
    Vdsp__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
        t->traceChgThis(vlSymsp, vcdp, code);
    }
}

//======================


void Vdsp::traceChgThis(Vdsp__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vdsp* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
        if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
                               | (vlTOPp->__Vm_traceActivity 
                                  >> 3U))))) {
            vlTOPp->traceChgThis__4(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
                               | (vlTOPp->__Vm_traceActivity 
                                  >> 5U))))) {
            vlTOPp->traceChgThis__5(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
                               | (vlTOPp->__Vm_traceActivity 
                                  >> 6U))))) {
            vlTOPp->traceChgThis__6(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((0x10U & vlTOPp->__Vm_traceActivity))) {
            vlTOPp->traceChgThis__7(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((0x20U & vlTOPp->__Vm_traceActivity))) {
            vlTOPp->traceChgThis__8(vlSymsp, vcdp, code);
        }
        vlTOPp->traceChgThis__9(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vdsp::traceChgThis__2(Vdsp__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vdsp* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+1,(vlTOPp->pwmdac__DOT__signal_register),16);
    }
}

void Vdsp::traceChgThis__3(Vdsp__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vdsp* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+9,(vlTOPp->mac4__DOT__check));
        vcdp->chgBus(c+17,(vlTOPp->mac4__DOT__out),32);
    }
}

void Vdsp::traceChgThis__4(Vdsp__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vdsp* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+25,(vlTOPp->sync__DOT__intermediate));
    }
}

void Vdsp::traceChgThis__5(Vdsp__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vdsp* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+33,(vlTOPp->i2s_decoder__DOT__sck_p));
        vcdp->chgBit(c+41,(vlTOPp->i2s_decoder__DOT__sck_n));
        vcdp->chgBit(c+49,(vlTOPp->i2s_decoder__DOT__ws_p));
        vcdp->chgBit(c+57,(vlTOPp->i2s_decoder__DOT__ws_n));
        vcdp->chgBus(c+65,(vlTOPp->i2s_decoder__DOT__u_edge_detect_sck__DOT__ff),2);
        vcdp->chgBus(c+73,(vlTOPp->i2s_decoder__DOT__u_edge_detect_ws__DOT__ff),2);
    }
}

void Vdsp::traceChgThis__6(Vdsp__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vdsp* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+81,(vlTOPp->dsdac__DOT__signal_register),17);
        vcdp->chgBus(c+89,(vlTOPp->dsdac__DOT__ddc),17);
    }
}

void Vdsp::traceChgThis__7(Vdsp__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vdsp* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+97,(vlTOPp->dds__DOT__phase_accumulator_1),32);
        vcdp->chgBus(c+105,(vlTOPp->dds__DOT__phase_accumulator_out),32);
    }
}

void Vdsp::traceChgThis__8(Vdsp__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vdsp* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+113,(vlTOPp->i2s_decoder__DOT__buffer),16);
        vcdp->chgBus(c+121,(vlTOPp->i2s_decoder__DOT__counter),4);
    }
}

void Vdsp::traceChgThis__9(Vdsp__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vdsp* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+129,(vlTOPp->sync__02Eclk));
        vcdp->chgBit(c+137,(vlTOPp->sync__02Ein));
        vcdp->chgBit(c+145,(vlTOPp->rst));
        vcdp->chgBit(c+153,(vlTOPp->sync_out));
        vcdp->chgBit(c+161,(vlTOPp->dds__02Eclk));
        vcdp->chgBit(c+169,(vlTOPp->dds__02Een));
        vcdp->chgBus(c+177,(vlTOPp->freq),32);
        vcdp->chgBus(c+185,(vlTOPp->phase),32);
        vcdp->chgBus(c+193,(vlTOPp->dds__02Esignal),16);
        vcdp->chgBit(c+201,(vlTOPp->dsdac__02Eclk));
        vcdp->chgBit(c+209,(vlTOPp->dsdac__02Een));
        vcdp->chgBus(c+217,(vlTOPp->dsdac__02Esignal),16);
        vcdp->chgBit(c+225,(vlTOPp->dsdac__02Ebitstream));
        vcdp->chgBit(c+233,(vlTOPp->pwmdac__02Eclk));
        vcdp->chgBus(c+241,(vlTOPp->pwmdac__02Esignal),16);
        vcdp->chgBit(c+249,(vlTOPp->pwmdac__02Ebitstream));
        vcdp->chgBit(c+257,(vlTOPp->lfsr__02Eclk));
        vcdp->chgBit(c+265,(vlTOPp->lfsr__02Een));
        vcdp->chgBus(c+273,(vlTOPp->random_num),24);
        vcdp->chgBit(c+281,(vlTOPp->mac4__02Eclk));
        vcdp->chgBit(c+289,(vlTOPp->mac4__02Een));
        vcdp->chgBus(c+297,(vlTOPp->mac4__02Ein),32);
        vcdp->chgBus(c+305,(vlTOPp->a0),16);
        vcdp->chgBus(c+313,(vlTOPp->c0),16);
        vcdp->chgBus(c+321,(vlTOPp->a1),16);
        vcdp->chgBus(c+329,(vlTOPp->c1),16);
        vcdp->chgBus(c+337,(vlTOPp->a2),16);
        vcdp->chgBus(c+345,(vlTOPp->c2),16);
        vcdp->chgBus(c+353,(vlTOPp->a3),16);
        vcdp->chgBus(c+361,(vlTOPp->c3),16);
        vcdp->chgBus(c+369,(vlTOPp->result),32);
        vcdp->chgBit(c+377,(vlTOPp->i2s_decoder__02Eclk));
        vcdp->chgBit(c+385,(vlTOPp->sck));
        vcdp->chgBit(c+393,(vlTOPp->ws));
        vcdp->chgBit(c+401,(vlTOPp->sd));
        vcdp->chgBus(c+409,(vlTOPp->left_channel),16);
        vcdp->chgBus(c+417,(vlTOPp->right_channel),16);
        vcdp->chgBit(c+425,(vlTOPp->sample_clk));
        vcdp->chgBit(c+433,((1U & (((vlTOPp->random_num 
                                     ^ (vlTOPp->random_num 
                                        >> 1U)) ^ (vlTOPp->random_num 
                                                   >> 2U)) 
                                   ^ (vlTOPp->random_num 
                                      >> 7U)))));
    }
}
