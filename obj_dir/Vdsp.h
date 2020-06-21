// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VDSP_H_
#define _VDSP_H_  // guard

#include "verilated_heavy.h"

//==========

class Vdsp__Syms;
class Vdsp_VerilatedVcd;


//----------

VL_MODULE(Vdsp) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(sync__02Eclk,0,0);
    VL_IN8(dds__02Eclk,0,0);
    VL_IN8(dsdac__02Eclk,0,0);
    VL_IN8(pwmdac__02Eclk,0,0);
    VL_IN8(lfsr__02Eclk,0,0);
    VL_IN8(i2s_decoder__02Eclk,0,0);
    VL_IN8(sync__02Ein,0,0);
    VL_IN8(rst,0,0);
    VL_OUT8(sync_out,0,0);
    VL_IN8(dds__02Een,0,0);
    VL_IN8(dsdac__02Een,0,0);
    VL_OUT8(dsdac__02Ebitstream,0,0);
    VL_OUT8(pwmdac__02Ebitstream,0,0);
    VL_IN8(lfsr__02Een,0,0);
    VL_IN8(mac4__02Eclk,0,0);
    VL_IN8(mac4__02Een,0,0);
    VL_IN8(sck,0,0);
    VL_IN8(ws,0,0);
    VL_IN8(sd,0,0);
    VL_OUT8(sample_clk,0,0);
    VL_OUT16(dds__02Esignal,15,0);
    VL_IN16(dsdac__02Esignal,15,0);
    VL_IN16(pwmdac__02Esignal,15,0);
    VL_IN16(a0,15,0);
    VL_IN16(c0,15,0);
    VL_IN16(a1,15,0);
    VL_IN16(c1,15,0);
    VL_IN16(a2,15,0);
    VL_IN16(c2,15,0);
    VL_IN16(a3,15,0);
    VL_IN16(c3,15,0);
    VL_OUT16(left_channel,15,0);
    VL_OUT16(right_channel,15,0);
    VL_IN(freq,31,0);
    VL_IN(phase,31,0);
    VL_OUT(random_num,23,0);
    VL_IN(mac4__02Ein,31,0);
    VL_OUT(result,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*0:0*/ sync__DOT__intermediate;
    CData/*0:0*/ lfsr__DOT__bit_insert;
    CData/*0:0*/ mac4__DOT__check;
    CData/*3:0*/ i2s_decoder__DOT__counter;
    CData/*0:0*/ i2s_decoder__DOT__sck_p;
    CData/*0:0*/ i2s_decoder__DOT__sck_n;
    CData/*0:0*/ i2s_decoder__DOT__ws_p;
    CData/*0:0*/ i2s_decoder__DOT__ws_n;
    CData/*1:0*/ i2s_decoder__DOT__u_edge_detect_sck__DOT__ff;
    CData/*1:0*/ i2s_decoder__DOT__u_edge_detect_ws__DOT__ff;
    SData/*15:0*/ pwmdac__DOT__signal_register;
    SData/*15:0*/ i2s_decoder__DOT__buffer;
    IData/*31:0*/ dds__DOT__phase_accumulator_1;
    IData/*31:0*/ dds__DOT__phase_accumulator_out;
    IData/*16:0*/ dsdac__DOT__signal_register;
    IData/*16:0*/ dsdac__DOT__ddc;
    IData/*31:0*/ mac4__DOT__out;
    SData/*15:0*/ dds__DOT__sine_table[512];
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __Vclklast__TOP__pwmdac__02Eclk;
    CData/*0:0*/ __Vclklast__TOP__sync__02Eclk;
    CData/*0:0*/ __Vclklast__TOP__lfsr__02Eclk;
    CData/*0:0*/ __Vclklast__TOP__dds__02Eclk;
    CData/*0:0*/ __Vclklast__TOP__i2s_decoder__02Eclk;
    CData/*0:0*/ __Vclklast__TOP__dsdac__02Eclk;
    IData/*31:0*/ __Vm_traceActivity;
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vdsp__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vdsp);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vdsp(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vdsp();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vdsp__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vdsp__Syms* symsp, bool first);
  private:
    static QData _change_request(Vdsp__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__2(Vdsp__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vdsp__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vdsp__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vdsp__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__9(Vdsp__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__1(Vdsp__Syms* __restrict vlSymsp);
    static void _sequent__TOP__4(Vdsp__Syms* __restrict vlSymsp);
    static void _sequent__TOP__5(Vdsp__Syms* __restrict vlSymsp);
    static void _sequent__TOP__6(Vdsp__Syms* __restrict vlSymsp);
    static void _sequent__TOP__7(Vdsp__Syms* __restrict vlSymsp);
    static void _sequent__TOP__8(Vdsp__Syms* __restrict vlSymsp);
    static void _settle__TOP__10(Vdsp__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void traceChgThis(Vdsp__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__2(Vdsp__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__3(Vdsp__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__4(Vdsp__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__5(Vdsp__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__6(Vdsp__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__7(Vdsp__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__8(Vdsp__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__9(Vdsp__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceFullThis(Vdsp__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceFullThis__1(Vdsp__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInitThis(Vdsp__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInitThis__1(Vdsp__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
