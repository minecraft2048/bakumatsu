// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VI2S_H_
#define _VI2S_H_  // guard

#include "verilated.h"

//==========

class Vi2s__Syms;
class Vi2s_VerilatedVcd;


//----------

VL_MODULE(Vi2s) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(sync__02Eclk,0,0);
    VL_IN8(i2s_decoder__02Eclk,0,0);
    VL_IN8(in,0,0);
    VL_IN8(rst,0,0);
    VL_OUT8(sync_out,0,0);
    VL_IN8(sck,0,0);
    VL_IN8(ws,0,0);
    VL_IN8(sd,0,0);
    VL_OUT8(sample_clk,0,0);
    VL_OUT16(left_channel,15,0);
    VL_OUT16(right_channel,15,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*0:0*/ sync__DOT__intermediate;
    CData/*3:0*/ i2s_decoder__DOT__counter;
    CData/*0:0*/ i2s_decoder__DOT__sck_p;
    CData/*0:0*/ i2s_decoder__DOT__sck_n;
    CData/*0:0*/ i2s_decoder__DOT__ws_p;
    CData/*0:0*/ i2s_decoder__DOT__ws_n;
    CData/*1:0*/ i2s_decoder__DOT__u_edge_detect_sck__DOT__ff;
    CData/*1:0*/ i2s_decoder__DOT__u_edge_detect_ws__DOT__ff;
    SData/*15:0*/ i2s_decoder__DOT__buffer;
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __Vclklast__TOP__sync__02Eclk;
    CData/*0:0*/ __Vclklast__TOP__i2s_decoder__02Eclk;
    IData/*31:0*/ __Vm_traceActivity;
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vi2s__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vi2s);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vi2s(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vi2s();
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
    static void _eval_initial_loop(Vi2s__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vi2s__Syms* symsp, bool first);
  private:
    static QData _change_request(Vi2s__Syms* __restrict vlSymsp);
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vi2s__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vi2s__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vi2s__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__3(Vi2s__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__1(Vi2s__Syms* __restrict vlSymsp);
    static void _sequent__TOP__2(Vi2s__Syms* __restrict vlSymsp);
    static void _settle__TOP__4(Vi2s__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void traceChgThis(Vi2s__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__2(Vi2s__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__3(Vi2s__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__4(Vi2s__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__5(Vi2s__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceFullThis(Vi2s__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceFullThis__1(Vi2s__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInitThis(Vi2s__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInitThis__1(Vi2s__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
