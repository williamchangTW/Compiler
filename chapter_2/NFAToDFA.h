#ifndef _NFATODFA_H
#define _NFATODFA_H

#define MAX_STATE_NUM 64

typedef struct _NFAState
{
    char Transform;
    struct _NFAState *Next1;
    struct _NFAState *Next2;
    int Name;
    int AcceptFlag;
}NFAState;

typedef struct _NFAFragment
{
    NFAState *StartState;
    NFAState *AcceptState;
}NFAFragment;

typedef struct _Transform
{
    char TransformChar;
    int DFAStateIndex;
    NFAState *NFAlist[MAX_STATE_NUM];
    int NFAStateCount;
    struct _Transform *NextTrans;
}Transform;

typedef struct _DFAState
{
    NFAState *NFAlist[MAX_STATE_NUM];
    int NFAStateCount;
    Transform *firstTran;
}DFAState;

typedef struct _DFA
{
    DFAState *DFAlist[MAX_STATE_NUM];
    int length;
}DFA;

void Closure(NFAState *State, NFAState **StateArray, int *Count);
DFAState *CreateDFAState(Transform *pTransform);
Transform *CreateDFATransform(char TransformChar, NFAState **NFAStateArray, int Count);

int NFAStateIsSubset(DFA *pDFA, Transform *pTransform);
Transform *IsTransformExist(DFAState *pDFAState, char TransformChar);
void AddNFAStateArrayToTransforform(NFAState **NFAStateArray, int Count, Transform *pTransform);

DFA *post2dfa(DFA *pDFA, char *postfix);

extern const char VoidTrans;
extern NFAState *Start;

#endif