#include "NFAFragmentStack.h"

void InitNFAFragmentStack(NFAFragmentStack *ps)
{
    ps->top = -1;
}

void PushNFAFragment(NFAFragmentStack *ps, NFAFragment Elem)
{
    if (MAX_STACK_LENGTH-1 <= ps->top)
        return;
    ps->top++;
    ps->buffer[ps->top] = Elem;
    return;
}

NFAFragment PopNFAFragment(NFAFragmentStack *ps)
{
    int pos;
    NFAFragment fragment = {0, 0};
    
    if(NFAFragmentStackEmpty(ps))
        return fragment;

    pos = ps->top;
    ps->top--;

    return ps->buffer[pos];
}

int NFAFragmentStackEmpty(NFAFragmentStack *ps)
{
    return - 1 == ps->top ? 1:0;
}