// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtop__Syms.h"
#include "Vtop.h"



// FUNCTIONS
Vtop__Syms::Vtop__Syms(Vtop* topp, const char* namep)
    // Setup locals
    : __Vm_namep(namep)
    , __Vm_activity(false)
    , __Vm_didInit(false)
    // Setup submodule names
{
    // Pointer to top level
    TOPp = topp;
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOPp->__Vconfigure(this, true);
    // Setup scopes
    __Vscope_TOP.configure(this, name(), "TOP", "TOP", VerilatedScope::SCOPE_OTHER);
    __Vscope_ema_filter.configure(this, name(), "ema_filter", "ema_filter", VerilatedScope::SCOPE_MODULE);
    
    // Setup scope hierarchy
    __Vhier.add(0, &__Vscope_ema_filter);
    
    // Setup export functions
    for (int __Vfinal=0; __Vfinal<2; __Vfinal++) {
        __Vscope_TOP.varInsert(__Vfinal,"alpha", &(TOPp->alpha), VLVT_UINT16,VLVD_IN|VLVF_PUB_RW,1 ,15,0);
        __Vscope_TOP.varInsert(__Vfinal,"clk", &(TOPp->clk), VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"filtered", &(TOPp->filtered), VLVT_UINT16,VLVD_OUT|VLVF_PUB_RW,1 ,15,0);
        __Vscope_TOP.varInsert(__Vfinal,"sample_clk", &(TOPp->sample_clk), VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"signal_in", &(TOPp->signal_in), VLVT_UINT16,VLVD_IN|VLVF_PUB_RW,1 ,15,0);
        __Vscope_ema_filter.varInsert(__Vfinal,"alpha", &(TOPp->ema_filter__DOT__alpha), VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,1 ,15,0);
        __Vscope_ema_filter.varInsert(__Vfinal,"clk", &(TOPp->ema_filter__DOT__clk), VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_ema_filter.varInsert(__Vfinal,"filtered", &(TOPp->ema_filter__DOT__filtered), VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,1 ,15,0);
        __Vscope_ema_filter.varInsert(__Vfinal,"sample_clk", &(TOPp->ema_filter__DOT__sample_clk), VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_ema_filter.varInsert(__Vfinal,"signal_in", &(TOPp->ema_filter__DOT__signal_in), VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,1 ,15,0);
        __Vscope_ema_filter.varInsert(__Vfinal,"state", &(TOPp->ema_filter__DOT__state), VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_ema_filter.varInsert(__Vfinal,"state_trunc", &(TOPp->ema_filter__DOT__state_trunc), VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,1 ,15,0);
    }
}
