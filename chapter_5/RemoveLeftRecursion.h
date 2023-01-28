#ifndef _REMOVELEFTRECURSION_H
#define _REMOVELEFTRECURSION_H

#include <stdio.h>

#define MAX_STR_LENGTH 64

struct _Rule;

typedef struct _RuleSymbol
{
    struct _RuleSymbol *pNextSymbol;
    struct _RuleSymbol *pOther;
    int isToken;
    char TokenName[MAX_STR_LENGTH];
    struct _Rule *pRule;
}RuleSymbol;

typedef struct _Rule
{
    char RuleName[MAX_STR_LENGTH];
    struct _RuleSymbol *pFirstSymbol;
    struct _Rule *pNextRule;
}Rule;

Rule *InitRules();
Rule *CreateRule(const char *pRuleName);
RuleSymbol *CreateSymbol();
Rule *FindRule(Rule *pHead, const char *RuleName);

int RuleHasLeftRecursion(Rule *pRule);
void AddSymbolToSelect(RuleSymbol *pSelect, RuleSymbol *pNewSymbol);
void AddSelectToRule(Rule *pRule, RuleSymbol *pNewSelect);
RuleSymbol *CopySymbol(const RuleSymbol *pSymbolTemplate);
RuleSymbol *CopySelect(const RuleSymbol *pSelectTemplate);
void FreeSelect(RuleSymbol *pSelect);
RuleSymbol *ReplaceSelect(const RuleSymbol *pSelectTemplate);
void RemoveLeftRecursion(Rule *pHead);

void PrintRule(Rule *pHead);

extern const char *VoidSymbol;
extern const char *Postfix;

#endif