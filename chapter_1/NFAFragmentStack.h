/**
 * @file NFAFragmentStack.h
 * @author William Chang (williamchangTW@github.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef _NFAFRAGMENTSTACK_H
#define _NFAFRAGMENTSTACK_H

#include "RegexpToNFA.h"

#define MAX_STACK_LENGTH 1024

typedef struct NFAFragmentStack
{
    NFAFragment buffer[MAX_STACK_LENGTH];
    int top;
}NFAFragmentStack;

void InitNFAFragmentStack(NFAFragmentStack *pS);
void PushNFAFragment(NFAFragmentStack *os, NFAFragment Elem);
NFAFragment PopNFAFragment(NFAFragmentStack *ps);
int NFAFragmentStackEmpty(NFAFragmentStack *ps);


#endif