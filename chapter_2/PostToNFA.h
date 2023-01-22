#ifndef _POSTTONFA_H
#define _POSTTONFA_H

#include "NFAToDFA.h"

NFAState *CreateNFAState();
NFAFragment MakeNFAFragment(NFAState *StartState, NFAState *AcceptState);
NFAState *post2nfa(char *postfix);

#endif