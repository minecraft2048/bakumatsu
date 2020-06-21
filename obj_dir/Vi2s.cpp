// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vi2s.h for the primary calling header

#include "Vi2s.h"
#include "Vi2s__Syms.h"

//==========

VL_CTOR_IMP(Vi2s) {
    Vi2s__Syms* __restrict vlSymsp = __VlSymsp = new Vi2s__Syms(this, name());
    Vi2s* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vi2s::__Vconfigure(Vi2s__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vi2s::~Vi2s() {
    delete __VlSymsp; __VlSymsp=NULL;
}

void Vi2s::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vi2s::eval\n"); );
    Vi2s__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vi2s* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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

void Vi2s::_eval_initial_loop(Vi2s__Syms* __restrict vlSymsp) {
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

VL_INLINE_OPT void Vi2s::_sequent__TOP__1(Vi2s__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s::_sequent__TOP__1\n"); );
    Vi2s* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->sync_out = ((~ (IData)(vlTOPp->rst)) & (IData)(vlTOPp->sync__DOT__intermediate));
    vlTOPp->sync__DOT__intermediate = ((~ (IData)(vlTOPp->rst)) 
                                       & (IData)(vlTOPp->in));
}

VL_INLINE_OPT void Vi2s::_sequent__TOP__2(Vi2s__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s::_sequent__TOP__2\n"); );
    Vi2s* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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

void Vi2s::_initial__TOP__3(Vi2s__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s::_initial__TOP__3\n"); );
    Vi2s* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->i2s_decoder__DOT__u_edge_detect_sck__DOT__ff = 0U;
    vlTOPp->i2s_decoder__DOT__u_edge_detect_ws__DOT__ff = 0U;
    vlTOPp->sync__DOT__intermediate = 0U;
    vlTOPp->sync_out = 0U;
}

void Vi2s::_settle__TOP__4(Vi2s__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s::_settle__TOP__4\n"); );
    Vi2s* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->i2s_decoder__DOT__sck_n = ((1U != (IData)(vlTOPp->i2s_decoder__DOT__u_edge_detect_sck__DOT__ff)) 
                                       & (2U == (IData)(vlTOPp->i2s_decoder__DOT__u_edge_detect_sck__DOT__ff)));
    vlTOPp->i2s_decoder__DOT__sck_p = (1U == (IData)(vlTOPp->i2s_decoder__DOT__u_edge_detect_sck__DOT__ff));
    vlTOPp->i2s_decoder__DOT__ws_p = (1U == (IData)(vlTOPp->i2s_decoder__DOT__u_edge_detect_ws__DOT__ff));
    vlTOPp->i2s_decoder__DOT__ws_n = ((1U != (IData)(vlTOPp->i2s_decoder__DOT__u_edge_detect_ws__DOT__ff)) 
                                      & (2U == (IData)(vlTOPp->i2s_decoder__DOT__u_edge_detect_ws__DOT__ff)));
    vlTOPp->sample_clk = vlTOPp->i2s_decoder__DOT__ws_n;
}

void Vi2s::_eval(Vi2s__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s::_eval\n"); );
    Vi2s* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->sync__02Eclk) & (~ (IData)(vlTOPp->__Vclklast__TOP__sync__02Eclk)))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
        vlTOPp->__Vm_traceActivity = (2U | vlTOPp->__Vm_traceActivity);
    }
    if (((IData)(vlTOPp->i2s_decoder__02Eclk) & (~ (IData)(vlTOPp->__Vclklast__TOP__i2s_decoder__02Eclk)))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
        vlTOPp->__Vm_traceActivity = (4U | vlTOPp->__Vm_traceActivity);
    }
    // Final
    vlTOPp->__Vclklast__TOP__sync__02Eclk = vlTOPp->sync__02Eclk;
    vlTOPp->__Vclklast__TOP__i2s_decoder__02Eclk = vlTOPp->i2s_decoder__02Eclk;
}

void Vi2s::_eval_initial(Vi2s__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s::_eval_initial\n"); );
    Vi2s* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__sync__02Eclk = vlTOPp->sync__02Eclk;
    vlTOPp->__Vclklast__TOP__i2s_decoder__02Eclk = vlTOPp->i2s_decoder__02Eclk;
    vlTOPp->_initial__TOP__3(vlSymsp);
    vlTOPp->__Vm_traceActivity = (1U | vlTOPp->__Vm_traceActivity);
}

void Vi2s::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s::final\n"); );
    // Variables
    Vi2s__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vi2s* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vi2s::_eval_settle(Vi2s__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s::_eval_settle\n"); );
    Vi2s* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__4(vlSymsp);
    vlTOPp->__Vm_traceActivity = (1U | vlTOPp->__Vm_traceActivity);
}

VL_INLINE_OPT QData Vi2s::_change_request(Vi2s__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s::_change_request\n"); );
    Vi2s* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vi2s::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((sync__02Eclk & 0xfeU))) {
        Verilated::overWidthError("sync.clk");}
    if (VL_UNLIKELY((in & 0xfeU))) {
        Verilated::overWidthError("in");}
    if (VL_UNLIKELY((rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
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

void Vi2s::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s::_ctor_var_reset\n"); );
    // Body
    sync__02Eclk = VL_RAND_RESET_I(1);
    in = VL_RAND_RESET_I(1);
    rst = VL_RAND_RESET_I(1);
    sync_out = VL_RAND_RESET_I(1);
    i2s_decoder__02Eclk = VL_RAND_RESET_I(1);
    sck = VL_RAND_RESET_I(1);
    ws = VL_RAND_RESET_I(1);
    sd = VL_RAND_RESET_I(1);
    left_channel = VL_RAND_RESET_I(16);
    right_channel = VL_RAND_RESET_I(16);
    sample_clk = VL_RAND_RESET_I(1);
    sync__DOT__intermediate = VL_RAND_RESET_I(1);
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
