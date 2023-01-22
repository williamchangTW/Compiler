#ifndef _NFASTATESTACK_H
#define _NFASTATESTACK_H

#define MAX_STACK_LENGTH 1024

typedef struct _NFAStateStack
{
    NFAState *buffer[MAX_STACK_LENGTH];
    int top;
}NFAStateStack;

void InitNFAStateStack(NFAStateStack *ps);
void PushNFAState(NFAStateStack *ps, NFAState *Elem);
NFAState *PopNFAState(NFAStateStack *ps);
int NFAStateStackEmpty(NFAStateStack *ps);

#endif