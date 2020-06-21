// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdsp.h for the primary calling header

#include "Vdsp.h"
#include "Vdsp__Syms.h"

//==========

VL_CTOR_IMP(Vdsp) {
    Vdsp__Syms* __restrict vlSymsp = __VlSymsp = new Vdsp__Syms(this, name());
    Vdsp* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vdsp::__Vconfigure(Vdsp__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vdsp::~Vdsp() {
    delete __VlSymsp; __VlSymsp=NULL;
}

void Vdsp::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vdsp::eval\n"); );
    Vdsp__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vdsp* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
#ifdef VM_TRACE
    // Tracing
#endif  // VM_TRACE
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("basic_bits.sv", 4, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vdsp::_eval_initial_loop(Vdsp__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("basic_bits.sv", 4, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vdsp::_sequent__TOP__1(Vdsp__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdsp::_sequent__TOP__1\n"); );
    Vdsp* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->pwmdac__DOT__signal_register = (0xffffU 
                                            & ((IData)(1U) 
                                               + (IData)(vlTOPp->pwmdac__DOT__signal_register)));
    vlTOPp->pwmdac__02Ebitstream = ((IData)(vlTOPp->pwmdac__DOT__signal_register) 
                                    >= (IData)(vlTOPp->pwmdac__02Esignal));
}

VL_INLINE_OPT void Vdsp::_combo__TOP__2(Vdsp__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdsp::_combo__TOP__2\n"); );
    Vdsp* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->mac4__DOT__check = (1U & (IData)((VL_ULL(1) 
                                              & (((((VL_EXTENDS_QI(33,32, vlTOPp->mac4__02Ein) 
                                                     + 
                                                     VL_MULS_QQQ(33,33,33, 
                                                                 (VL_ULL(0x1ffffffff) 
                                                                  & VL_EXTENDS_QI(33,16, (IData)(vlTOPp->a0))), 
                                                                 (VL_ULL(0x1ffffffff) 
                                                                  & VL_EXTENDS_QI(33,16, (IData)(vlTOPp->c0))))) 
                                                    + 
                                                    VL_MULS_QQQ(33,33,33, 
                                                                (VL_ULL(0x1ffffffff) 
                                                                 & VL_EXTENDS_QI(33,16, (IData)(vlTOPp->a1))), 
                                                                (VL_ULL(0x1ffffffff) 
                                                                 & VL_EXTENDS_QI(33,16, (IData)(vlTOPp->c1))))) 
                                                   + 
                                                   VL_MULS_QQQ(33,33,33, 
                                                               (VL_ULL(0x1ffffffff) 
                                                                & VL_EXTENDS_QI(33,16, (IData)(vlTOPp->a2))), 
                                                               (VL_ULL(0x1ffffffff) 
                                                                & VL_EXTENDS_QI(33,16, (IData)(vlTOPp->c2))))) 
                                                  + 
                                                  VL_MULS_QQQ(33,33,33, 
                                                              (VL_ULL(0x1ffffffff) 
                                                               & VL_EXTENDS_QI(33,16, (IData)(vlTOPp->a3))), 
                                                              (VL_ULL(0x1ffffffff) 
                                                               & VL_EXTENDS_QI(33,16, (IData)(vlTOPp->c3))))) 
                                                 >> 0x20U))));
    vlTOPp->mac4__DOT__out = (((((IData)((VL_ULL(0x1ffffffff) 
                                          & VL_EXTENDS_QI(33,32, vlTOPp->mac4__02Ein))) 
                                 + (IData)((VL_ULL(0x1ffffffff) 
                                            & VL_MULS_QQQ(33,33,33, 
                                                          (VL_ULL(0x1ffffffff) 
                                                           & VL_EXTENDS_QI(33,16, (IData)(vlTOPp->a0))), 
                                                          (VL_ULL(0x1ffffffff) 
                                                           & VL_EXTENDS_QI(33,16, (IData)(vlTOPp->c0))))))) 
                                + (IData)((VL_ULL(0x1ffffffff) 
                                           & VL_MULS_QQQ(33,33,33, 
                                                         (VL_ULL(0x1ffffffff) 
                                                          & VL_EXTENDS_QI(33,16, (IData)(vlTOPp->a1))), 
                                                         (VL_ULL(0x1ffffffff) 
                                                          & VL_EXTENDS_QI(33,16, (IData)(vlTOPp->c1))))))) 
                               + (IData)((VL_ULL(0x1ffffffff) 
                                          & VL_MULS_QQQ(33,33,33, 
                                                        (VL_ULL(0x1ffffffff) 
                                                         & VL_EXTENDS_QI(33,16, (IData)(vlTOPp->a2))), 
                                                        (VL_ULL(0x1ffffffff) 
                                                         & VL_EXTENDS_QI(33,16, (IData)(vlTOPp->c2))))))) 
                              + (IData)((VL_ULL(0x1ffffffff) 
                                         & VL_MULS_QQQ(33,33,33, 
                                                       (VL_ULL(0x1ffffffff) 
                                                        & VL_EXTENDS_QI(33,16, (IData)(vlTOPp->a3))), 
                                                       (VL_ULL(0x1ffffffff) 
                                                        & VL_EXTENDS_QI(33,16, (IData)(vlTOPp->c3)))))));
    vlTOPp->result = ((1U == (((IData)(vlTOPp->mac4__DOT__check) 
                               << 1U) | (1U & (vlTOPp->mac4__DOT__out 
                                               >> 0x1fU))))
                       ? 0x7fffffffU : ((2U == (((IData)(vlTOPp->mac4__DOT__check) 
                                                 << 1U) 
                                                | (1U 
                                                   & (vlTOPp->mac4__DOT__out 
                                                      >> 0x1fU))))
                                         ? 0x80000000U
                                         : vlTOPp->mac4__DOT__out));
}

VL_INLINE_OPT void Vdsp::_sequent__TOP__4(Vdsp__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdsp::_sequent__TOP__4\n"); );
    Vdsp* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->sync_out = ((~ (IData)(vlTOPp->rst)) & (IData)(vlTOPp->sync__DOT__intermediate));
    vlTOPp->sync__DOT__intermediate = ((~ (IData)(vlTOPp->rst)) 
                                       & (IData)(vlTOPp->sync__02Ein));
}

VL_INLINE_OPT void Vdsp::_sequent__TOP__5(Vdsp__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdsp::_sequent__TOP__5\n"); );
    Vdsp* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->lfsr__02Een) {
        vlTOPp->random_num = (((IData)(vlTOPp->lfsr__DOT__bit_insert) 
                               << 0x17U) | (0x7fffffU 
                                            & (vlTOPp->random_num 
                                               >> 1U)));
    }
    vlTOPp->lfsr__DOT__bit_insert = (1U & (((vlTOPp->random_num 
                                             ^ (vlTOPp->random_num 
                                                >> 1U)) 
                                            ^ (vlTOPp->random_num 
                                               >> 2U)) 
                                           ^ (vlTOPp->random_num 
                                              >> 7U)));
}

VL_INLINE_OPT void Vdsp::_sequent__TOP__6(Vdsp__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdsp::_sequent__TOP__6\n"); );
    Vdsp* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    IData/*31:0*/ __Vdly__dds__DOT__phase_accumulator_1;
    // Body
    __Vdly__dds__DOT__phase_accumulator_1 = vlTOPp->dds__DOT__phase_accumulator_1;
    vlTOPp->dds__02Esignal = ((IData)(vlTOPp->dds__02Een)
                               ? vlTOPp->dds__DOT__sine_table
                              [(0x1ffU & (vlTOPp->dds__DOT__phase_accumulator_out 
                                          >> 0x17U))]
                               : 0U);
    if (vlTOPp->dds__02Een) {
        __Vdly__dds__DOT__phase_accumulator_1 = (vlTOPp->dds__DOT__phase_accumulator_1 
                                                 + vlTOPp->freq);
        vlTOPp->dds__DOT__phase_accumulator_out = (vlTOPp->dds__DOT__phase_accumulator_1 
                                                   + vlTOPp->phase);
    }
    vlTOPp->dds__DOT__phase_accumulator_1 = __Vdly__dds__DOT__phase_accumulator_1;
}

VL_INLINE_OPT void Vdsp::_sequent__TOP__7(Vdsp__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdsp::_sequent__TOP__7\n"); );
    Vdsp* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->i2s_decoder__DOT__u_edge_detect_sck__DOT__ff 
        = ((2U & ((IData)(vlTOPp->i2s_decoder__DOT__u_edge_detect_sck__DOT__ff) 
                  << 1U)) | (IData)(vlTOPp->sck));
    if (vlTOPp->i2s_decoder__DOT__sck_n) {
        if (((IData)(vlTOPp->i2s_decoder__DOT__ws_p) 
             | (IData)(vlTOPp->i2s_decoder__DOT__ws_n))) {
            vlTOPp->i2s_decoder__DOT__counter = 0xfU;
        } else {
            if ((0U != (IData)(vlTOPp->i2s_decoder__DOT__counter))) {
                vlTOPp->i2s_decoder__DOT__counter = 
                    (0xfU & ((IData)(vlTOPp->i2s_decoder__DOT__counter) 
                             - (IData)(1U)));
            }
        }
    }
    vlTOPp->i2s_decoder__DOT__u_edge_detect_ws__DOT__ff 
        = ((2U & ((IData)(vlTOPp->i2s_decoder__DOT__u_edge_detect_ws__DOT__ff) 
                  << 1U)) | (IData)(vlTOPp->ws));
    if (vlTOPp->i2s_decoder__DOT__sck_p) {
        if (vlTOPp->i2s_decoder__DOT__ws_p) {
            vlTOPp->right_channel = vlTOPp->i2s_decoder__DOT__buffer;
        }
    }
    if (vlTOPp->i2s_decoder__DOT__sck_p) {
        if ((1U & (~ (IData)(vlTOPp->i2s_decoder__DOT__ws_p)))) {
            if (vlTOPp->i2s_decoder__DOT__ws_n) {
                vlTOPp->left_channel = vlTOPp->i2s_decoder__DOT__buffer;
            }
        }
    }
    vlTOPp->i2s_decoder__DOT__sck_n = ((1U != (IData)(vlTOPp->i2s_decoder__DOT__u_edge_detect_sck__DOT__ff)) 
                                       & (2U == (IData)(vlTOPp->i2s_decoder__DOT__u_edge_detect_sck__DOT__ff)));
    vlTOPp->i2s_decoder__DOT__ws_p = (1U == (IData)(vlTOPp->i2s_decoder__DOT__u_edge_detect_ws__DOT__ff));
    vlTOPp->i2s_decoder__DOT__ws_n = ((1U != (IData)(vlTOPp->i2s_decoder__DOT__u_edge_detect_ws__DOT__ff)) 
                                      & (2U == (IData)(vlTOPp->i2s_decoder__DOT__u_edge_detect_ws__DOT__ff)));
    vlTOPp->sample_clk = vlTOPp->i2s_decoder__DOT__ws_n;
    if (vlTOPp->i2s_decoder__DOT__sck_p) {
        vlTOPp->i2s_decoder__DOT__buffer = (((~ ((IData)(1U) 
                                                 << (IData)(vlTOPp->i2s_decoder__DOT__counter))) 
                                             & (IData)(vlTOPp->i2s_decoder__DOT__buffer)) 
                                            | ((IData)(vlTOPp->sd) 
                                               << (IData)(vlTOPp->i2s_decoder__DOT__counter)));
    }
    vlTOPp->i2s_decoder__DOT__sck_p = (1U == (IData)(vlTOPp->i2s_decoder__DOT__u_edge_detect_sck__DOT__ff));
}

VL_INLINE_OPT void Vdsp::_sequent__TOP__8(Vdsp__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdsp::_sequent__TOP__8\n"); );
    Vdsp* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->dsdac__02Een) {
        vlTOPp->dsdac__DOT__signal_register = (0x1ffffU 
                                               & ((vlTOPp->dsdac__DOT__signal_register 
                                                   + 
                                                   VL_EXTENDS_II(17,16, (IData)(vlTOPp->dsdac__02Esignal))) 
                                                  - vlTOPp->dsdac__DOT__ddc));
    }
    vlTOPp->dsdac__02Ebitstream = VL_LTS_III(1,32,32, 0U, 
                                             VL_EXTENDS_II(32,17, vlTOPp->dsdac__DOT__signal_register));
    vlTOPp->dsdac__DOT__ddc = (VL_LTS_III(1,32,32, 0U, 
                                          VL_EXTENDS_II(32,17, vlTOPp->dsdac__DOT__signal_register))
                                ? 0x7fffU : 0x18000U);
}

void Vdsp::_initial__TOP__9(Vdsp__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdsp::_initial__TOP__9\n"); );
    Vdsp* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    WData/*95:0*/ __Vtemp7[3];
    // Body
    vlTOPp->pwmdac__DOT__signal_register = 0U;
    vlTOPp->random_num = 0xabcdefU;
    vlTOPp->i2s_decoder__DOT__u_edge_detect_sck__DOT__ff = 0U;
    vlTOPp->dsdac__DOT__signal_register = 0U;
    vlTOPp->dsdac__DOT__ddc = 0U;
    vlTOPp->i2s_decoder__DOT__u_edge_detect_ws__DOT__ff = 0U;
    __Vtemp7[0U] = 0x2e6d656dU;
    __Vtemp7[1U] = 0x5f6c7574U;
    __Vtemp7[2U] = 0x73696e65U;
    VL_READMEM_N(true, 16, 512, 0, VL_CVT_PACK_STR_NW(3, __Vtemp7)
                 , vlTOPp->dds__DOT__sine_table, 0, ~VL_ULL(0));
    vlTOPp->sync__DOT__intermediate = 0U;
    vlTOPp->sync_out = 0U;
}

void Vdsp::_settle__TOP__10(Vdsp__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdsp::_settle__TOP__10\n"); );
    Vdsp* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->lfsr__DOT__bit_insert = (1U & (((vlTOPp->random_num 
                                             ^ (vlTOPp->random_num 
                                                >> 1U)) 
                                            ^ (vlTOPp->random_num 
                                               >> 2U)) 
                                           ^ (vlTOPp->random_num 
                                              >> 7U)));
    vlTOPp->i2s_decoder__DOT__sck_n = ((1U != (IData)(vlTOPp->i2s_decoder__DOT__u_edge_detect_sck__DOT__ff)) 
                                       & (2U == (IData)(vlTOPp->i2s_decoder__DOT__u_edge_detect_sck__DOT__ff)));
    vlTOPp->i2s_decoder__DOT__sck_p = (1U == (IData)(vlTOPp->i2s_decoder__DOT__u_edge_detect_sck__DOT__ff));
    vlTOPp->dsdac__02Ebitstream = VL_LTS_III(1,32,32, 0U, 
                                             VL_EXTENDS_II(32,17, vlTOPp->dsdac__DOT__signal_register));
    vlTOPp->dsdac__DOT__ddc = (VL_LTS_III(1,32,32, 0U, 
                                          VL_EXTENDS_II(32,17, vlTOPp->dsdac__DOT__signal_register))
                                ? 0x7fffU : 0x18000U);
    vlTOPp->i2s_decoder__DOT__ws_p = (1U == (IData)(vlTOPp->i2s_decoder__DOT__u_edge_detect_ws__DOT__ff));
    vlTOPp->i2s_decoder__DOT__ws_n = ((1U != (IData)(vlTOPp->i2s_decoder__DOT__u_edge_detect_ws__DOT__ff)) 
                                      & (2U == (IData)(vlTOPp->i2s_decoder__DOT__u_edge_detect_ws__DOT__ff)));
    vlTOPp->sample_clk = vlTOPp->i2s_decoder__DOT__ws_n;
}

void Vdsp::_eval(Vdsp__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdsp::_eval\n"); );
    Vdsp* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->pwmdac__02Eclk) & (~ (IData)(vlTOPp->__Vclklast__TOP__pwmdac__02Eclk)))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
        vlTOPp->__Vm_traceActivity = (2U | vlTOPp->__Vm_traceActivity);
    }
    vlTOPp->_combo__TOP__2(vlSymsp);
    vlTOPp->__Vm_traceActivity = (4U | vlTOPp->__Vm_traceActivity);
    if (((IData)(vlTOPp->sync__02Eclk) & (~ (IData)(vlTOPp->__Vclklast__TOP__sync__02Eclk)))) {
        vlTOPp->_sequent__TOP__4(vlSymsp);
        vlTOPp->__Vm_traceActivity = (8U | vlTOPp->__Vm_traceActivity);
    }
    if (((IData)(vlTOPp->lfsr__02Eclk) & (~ (IData)(vlTOPp->__Vclklast__TOP__lfsr__02Eclk)))) {
        vlTOPp->_sequent__TOP__5(vlSymsp);
    }
    if (((IData)(vlTOPp->dds__02Eclk) & (~ (IData)(vlTOPp->__Vclklast__TOP__dds__02Eclk)))) {
        vlTOPp->_sequent__TOP__6(vlSymsp);
        vlTOPp->__Vm_traceActivity = (0x10U | vlTOPp->__Vm_traceActivity);
    }
    if (((IData)(vlTOPp->i2s_decoder__02Eclk) & (~ (IData)(vlTOPp->__Vclklast__TOP__i2s_decoder__02Eclk)))) {
        vlTOPp->_sequent__TOP__7(vlSymsp);
        vlTOPp->__Vm_traceActivity = (0x20U | vlTOPp->__Vm_traceActivity);
    }
    if (((IData)(vlTOPp->dsdac__02Eclk) & (~ (IData)(vlTOPp->__Vclklast__TOP__dsdac__02Eclk)))) {
        vlTOPp->_sequent__TOP__8(vlSymsp);
        vlTOPp->__Vm_traceActivity = (0x40U | vlTOPp->__Vm_traceActivity);
    }
    // Final
    vlTOPp->__Vclklast__TOP__pwmdac__02Eclk = vlTOPp->pwmdac__02Eclk;
    vlTOPp->__Vclklast__TOP__sync__02Eclk = vlTOPp->sync__02Eclk;
    vlTOPp->__Vclklast__TOP__lfsr__02Eclk = vlTOPp->lfsr__02Eclk;
    vlTOPp->__Vclklast__TOP__dds__02Eclk = vlTOPp->dds__02Eclk;
    vlTOPp->__Vclklast__TOP__i2s_decoder__02Eclk = vlTOPp->i2s_decoder__02Eclk;
    vlTOPp->__Vclklast__TOP__dsdac__02Eclk = vlTOPp->dsdac__02Eclk;
}

void Vdsp::_eval_initial(Vdsp__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdsp::_eval_initial\n"); );
    Vdsp* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__pwmdac__02Eclk = vlTOPp->pwmdac__02Eclk;
    vlTOPp->__Vclklast__TOP__sync__02Eclk = vlTOPp->sync__02Eclk;
    vlTOPp->__Vclklast__TOP__lfsr__02Eclk = vlTOPp->lfsr__02Eclk;
    vlTOPp->__Vclklast__TOP__dds__02Eclk = vlTOPp->dds__02Eclk;
    vlTOPp->__Vclklast__TOP__i2s_decoder__02Eclk = vlTOPp->i2s_decoder__02Eclk;
    vlTOPp->__Vclklast__TOP__dsdac__02Eclk = vlTOPp->dsdac__02Eclk;
    vlTOPp->_initial__TOP__9(vlSymsp);
    vlTOPp->__Vm_traceActivity = (1U | vlTOPp->__Vm_traceActivity);
}

void Vdsp::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdsp::final\n"); );
    // Variables
    Vdsp__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vdsp* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vdsp::_eval_settle(Vdsp__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdsp::_eval_settle\n"); );
    Vdsp* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__2(vlSymsp);
    vlTOPp->__Vm_traceActivity = (1U | vlTOPp->__Vm_traceActivity);
    vlTOPp->_settle__TOP__10(vlSymsp);
}

VL_INLINE_OPT QData Vdsp::_change_request(Vdsp__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdsp::_change_request\n"); );
    Vdsp* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vdsp::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdsp::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((sync__02Eclk & 0xfeU))) {
        Verilated::overWidthError("sync.clk");}
    if (VL_UNLIKELY((sync__02Ein & 0xfeU))) {
        Verilated::overWidthError("sync.in");}
    if (VL_UNLIKELY((rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((dds__02Eclk & 0xfeU))) {
        Verilated::overWidthError("dds.clk");}
    if (VL_UNLIKELY((dds__02Een & 0xfeU))) {
        Verilated::overWidthError("dds.en");}
    if (VL_UNLIKELY((dsdac__02Eclk & 0xfeU))) {
        Verilated::overWidthError("dsdac.clk");}
    if (VL_UNLIKELY((dsdac__02Een & 0xfeU))) {
        Verilated::overWidthError("dsdac.en");}
    if (VL_UNLIKELY((pwmdac__02Eclk & 0xfeU))) {
        Verilated::overWidthError("pwmdac.clk");}
    if (VL_UNLIKELY((lfsr__02Eclk & 0xfeU))) {
        Verilated::overWidthError("lfsr.clk");}
    if (VL_UNLIKELY((lfsr__02Een & 0xfeU))) {
        Verilated::overWidthError("lfsr.en");}
    if (VL_UNLIKELY((mac4__02Eclk & 0xfeU))) {
        Verilated::overWidthError("mac4.clk");}
    if (VL_UNLIKELY((mac4__02Een & 0xfeU))) {
        Verilated::overWidthError("mac4.en");}
    if (VL_UNLIKELY((i2s_decoder__02Eclk & 0xfeU))) {
        Verilated::overWidthError("i2s_decoder.clk");}
    if (VL_UNLIKELY((sck & 0xfeU))) {
        Verilated::overWidthError("sck");}
    if (VL_UNLIKELY((ws & 0xfeU))) {
        Verilated::overWidthError("ws");}
    if (VL_UNLIKELY((sd & 0xfeU))) {
        Verilated::overWidthError("sd");}
}
#endif  // VL_DEBUG

void Vdsp::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdsp::_ctor_var_reset\n"); );
    // Body
    sync__02Eclk = VL_RAND_RESET_I(1);
    sync__02Ein = VL_RAND_RESET_I(1);
    rst = VL_RAND_RESET_I(1);
    sync_out = VL_RAND_RESET_I(1);
    dds__02Eclk = VL_RAND_RESET_I(1);
    dds__02Een = VL_RAND_RESET_I(1);
    freq = VL_RAND_RESET_I(32);
    phase = VL_RAND_RESET_I(32);
    dds__02Esignal = VL_RAND_RESET_I(16);
    dsdac__02Eclk = VL_RAND_RESET_I(1);
    dsdac__02Een = VL_RAND_RESET_I(1);
    dsdac__02Esignal = VL_RAND_RESET_I(16);
    dsdac__02Ebitstream = VL_RAND_RESET_I(1);
    pwmdac__02Eclk = VL_RAND_RESET_I(1);
    pwmdac__02Esignal = VL_RAND_RESET_I(16);
    pwmdac__02Ebitstream = VL_RAND_RESET_I(1);
    lfsr__02Eclk = VL_RAND_RESET_I(1);
    lfsr__02Een = VL_RAND_RESET_I(1);
    random_num = VL_RAND_RESET_I(24);
    mac4__02Eclk = VL_RAND_RESET_I(1);
    mac4__02Een = VL_RAND_RESET_I(1);
    mac4__02Ein = VL_RAND_RESET_I(32);
    a0 = VL_RAND_RESET_I(16);
    c0 = VL_RAND_RESET_I(16);
    a1 = VL_RAND_RESET_I(16);
    c1 = VL_RAND_RESET_I(16);
    a2 = VL_RAND_RESET_I(16);
    c2 = VL_RAND_RESET_I(16);
    a3 = VL_RAND_RESET_I(16);
    c3 = VL_RAND_RESET_I(16);
    result = VL_RAND_RESET_I(32);
    i2s_decoder__02Eclk = VL_RAND_RESET_I(1);
    sck = VL_RAND_RESET_I(1);
    ws = VL_RAND_RESET_I(1);
    sd = VL_RAND_RESET_I(1);
    left_channel = VL_RAND_RESET_I(16);
    right_channel = VL_RAND_RESET_I(16);
    sample_clk = VL_RAND_RESET_I(1);
    sync__DOT__intermediate = VL_RAND_RESET_I(1);
    dds__DOT__phase_accumulator_1 = VL_RAND_RESET_I(32);
    dds__DOT__phase_accumulator_out = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<512; ++__Vi0) {
            dds__DOT__sine_table[__Vi0] = VL_RAND_RESET_I(16);
    }}
    dsdac__DOT__signal_register = VL_RAND_RESET_I(17);
    dsdac__DOT__ddc = VL_RAND_RESET_I(17);
    pwmdac__DOT__signal_register = VL_RAND_RESET_I(16);
    lfsr__DOT__bit_insert = VL_RAND_RESET_I(1);
    mac4__DOT__check = VL_RAND_RESET_I(1);
    mac4__DOT__out = VL_RAND_RESET_I(32);
    i2s_decoder__DOT__buffer = VL_RAND_RESET_I(16);
    i2s_decoder__DOT__counter = VL_RAND_RESET_I(4);
    i2s_decoder__DOT__sck_p = VL_RAND_RESET_I(1);
    i2s_decoder__DOT__sck_n = VL_RAND_RESET_I(1);
    i2s_decoder__DOT__ws_p = VL_RAND_RESET_I(1);
    i2s_decoder__DOT__ws_n = VL_RAND_RESET_I(1);
    i2s_decoder__DOT__u_edge_detect_sck__DOT__ff = VL_RAND_RESET_I(2);
    i2s_decoder__DOT__u_edge_detect_ws__DOT__ff = VL_RAND_RESET_I(2);
    __Vm_traceActivity = 0;
}
