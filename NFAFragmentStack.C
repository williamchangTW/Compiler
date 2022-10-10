/**
 * @file NFAFragmentStack.C
 * @author williamchangTW (williamchangTW@github.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "NFAFragmentStack.h"

/**
 * @fn InitNFAFragmentStack
 * @brief 
 * 
 * @param pS 
 */
void InitNFAFragmentStack(NFAFragmentStack *ps)
{
    ps->top = -1;
}

int NFAFragmentStackEmpty(NFAFragmentStack *ps)
{
    return -1 == ps->top ? 1: 0;
}

/**
 * @fn
 * @brief 
 * 
 * @param ps - pointer to NFAFragmentStack structure 
 * @param ele - element which insert to NFAFragmentStack
 */
void PushNFAFragment(NFAFragmentStack *ps, NFAFragment ele)
{
    if (MAX_STACK_LENGTH - 1 <= pS->top)
        return;
    
    ps->top++;
    ps->buffer[ps->top] = ele;
    
    return;
}

/**
 * @fn PopNFAFragment
 * @brief pop the element from NFAFragmentStack
 * 
 * @param ps - pointer to NFAFragmentStack structure
 */
NFAFragment PopNFAFragment(NFAFragmentStack *ps)
{
    int pos;
    NFAFragment fragment = {0, 0};

    if (NFAFragmentStackEmpty(ps))
        return fragment;
    
    pos = ps->top;
    ps->top--;
    return ps->buffer[pos];
}

