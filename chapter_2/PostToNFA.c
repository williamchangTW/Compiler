#include <stdio.h>
#include <stdlib.h>
#include "PostToNFA.h"
#include "NFAFragmentStack.h"

NFAFragmentStack FragmentStack;

int nstate = 1;
NFAState *CreateNFAState()
{
    NFAState *s = (NFAState*)malloc(sizeof(NFAState));

    s->Name = nstate++;
    s->Transform = '\0';
    s->Next1 = NULL;
    s->Next2 = NULL;
    s->AcceptFlag = 0;
    
    return s;
}

NFAFragment MakeNFAFragment(NFAState *StartState, NFAState *AcceptState)
{
    NFAFragment n = {StartState, AcceptState};
    return n;
}

NFAState *post2nfa(char *postfix)
{
    char *p;
    
    NFAFragment fragment1, fragment2, fm;
    NFAFragment fragment = {0, 0};
    NFAState *NewStartState, *NewAcceptState;

    //TODO

    return fragment.StartState;
}