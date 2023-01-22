#include "NFAToDFA.h"
#include "NFAStateStack.h"

void InitNFAStateStack(NFAStateStack *ps)
{
    ps->top = -1;
}

void PushNFAState(NFAStateStack *ps, NFAState *Elem)
{
    if (MAX_STACK_LENGTH - 1 <= ps->top)
        return;
    
    ps->top++;
    ps->buffer[ps->top] = Elem;

    return;
}

NFAState *PopNFAState(NFAStateStack *ps)
{
    int pos;
    NFAState *State = 0;

    if (NFAStateStackEmpty(ps))
        return State;

    pos = ps->top;
    ps->top--;

    return ps->buffer[pos];
}

int NFAStateStackEmpty(NFAStateStack *ps)
{
    return - 1 == ps->top ? 1:0;
}