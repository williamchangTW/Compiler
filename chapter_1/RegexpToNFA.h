#ifndef _REGEXPTONFA_H
#define _REGEXPTONFA_H
#include <stdio.h>

typedef struct NFAState
{
    char Transform;
    struct NFAState *Next1;
    struct NFAState *Next2;
    int Name;
    int AcceptFlag;
}NFAState;

typedef struct NFAFragment
{
    NFAState *StartState;
    NFAState *AcceptState;
}NFAFragment;

NFAState *CreateNFAState();
NFAState *post2nfa(char *postfix);
NFAFragment MakeNFAFragment(NFAState *StartState, NFAState *AcceptState);

extern int nstate;
extern const char VoidTrans;
extern char *regexp;

#endif