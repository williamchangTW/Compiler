/**
 * @file main.c
 * @author William Chang(williamchangTW@github.com)
 * @brief main code to compiler
 * @version 0.1
 * @date 2022-10-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include "NFAToDFA.h"
#include "RegexpToPost.h"
#include "PostToNFA.h"
#include "NFAStateStack.h"
#include "NFAFragmentStack.h"

NFAFragmentStack FragmentStack;
NFAStateStack StateStack;

const char VoidTrans = '$';
char *regexp = "a(a|1)*";

int main(int argc, char **argv)
{
    char *post;
    DFA *dfa = (DFA*)malloc(sizeof(DFA));
    dfa->length = 0;

    post = re2post(regexp);
    dfa = post2dfa(dfa, post);

    return 0;
}

Transform *CreateDFATransform(char TransformChar, NFAState **NFAStateArray, int Count)
{
    int i;
    Transform *pTransform = (Transform*)malloc(sizeof(Transform));

    for (i = 0; i < Count; i++)
        pTransform->NFAlist[i] = NFAStateArray[i];
    
    pTransform->NFAStateCount = Count;
    pTransform->TransformChar = TransformChar;
    pTransform->DFAStateIndex = -1;
    pTransform->NextTrans = NULL;

    return pTransform;
}

DFAState *CreateDFAState(Transform *pTransform)
{
    int i;
    DFAState *pDFAState = (DFAState*)malloc(sizeof(DFAState));
    
    for (i = 0; i < pTransform->NFAStateCount; i++)
        pDFAState->NFAlist[i] = pTransform->NFAlist[i];

    pDFAState->NFAStateCount = pTransform->NFAStateCount;
    pDFAState->firstTran = NULL;

    return pDFAState;
}

int NFAStateIsSubset(DFA *pDFA, Transform *pTransform)
{
    //TODO
}

Transform *IsTransformExist(DFAState *pDFAState, char TransformChar)
{
    //TODO
}

void AddNFAStateArrayToTransform(NFAState **NFAStateArray, int Count, Transform *pTransform)
{
    //TODO
}

void Closure(NFAState *State, NFAState **StateArray, int *Count)
{
    InitNFAStateStack(&StateStack);

    //TODO
}

NFAState *Start = NULL;
DFA *post2dfa(DFA *pDFA, char *postfix)
{
    int i, j;
    Transform *pTFCursor;
    NFAState *NFAStateArray[MAX_STATE_NUM];
    int Count = 0;

    Start = post2nfa(postfix);

    //TODO

    return pDFA;
}