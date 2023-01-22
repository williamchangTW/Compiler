#ifndef _NFAFRAGMENTSTACK_H
#define _NFAFRAGMENTSTACK_H

#include "NFAToDFA.h"

#define MAX_STACK_LENGTH 1024

typedef struct _NFAFragmentStack
{
    NFAFragment buffer[MAX_STACK_LENGTH];
    int top;
}NFAFragmentStack;

void InitNFAFragmentStack(NFAFragmentStack *ps);
void PushNFAFragment(NFAFragmentStack *ps, NFAFragment Elem);
NFAFragment popNFAFragment(NFAFragmentStack *ps);
int NFAFragmentStackEmpty(NFAFragmentStack *ps);

#endif