#include "RemoveLeftRecursion.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

const char *VoidSymbol = "$ ";
const char *Postfix = "'";

int main(int argc, char **argv)
{
    Rule *pHead = InitRules();
    printf("Before Remove Left Recursion:\n");
    PrintRule(pHead);

    RemoveLeftRecursion(pHead);

    printf("After Remove Left Recursion:\n");
    PrintRule(pHead);

    return 0;
}

int SymbolNeedReplace(const Rule *pCurRule, const RuleSymbol *pSymbol)
{
    //TODO
}

RuleSymbol *CopySymbol(const RuleSymbol *pSymbolTemplate)
{
    //TODO
}

RuleSymbol *CopySelect(const RuleSymbol *pSelectTemplate)
{
    //TODO
}

RuleSymbol *ReplaceSelect(const RuleSymbol *pSelectTemplate)
{
    //TODO
}

void FreeSelect(RuleSymbol *pSelect)
{
    //TODO
}

int RuleHasLeftRecursion(Rule *pRule)
{
    //TODO
}

void AddSymbolToSelect(RuleSymbol *pSelect, RuleSymbol *pNewSymbol)
{
    //TODO
}

void AddSelectToRule(Rule *pRule, RuleSymbol *pNewSelect)
{
    //TODO
}

void RemoveLeftRecursion(Rule *pHead)
{
    Rule *pRule;
    RuleSymbol *pSelect;
    Rule *pNewRule;
    int isChange;
    RuleSymbol **pSelectPrePtr;

    //TODO
}

typedef struct _SYMBOL
{
    int isToken;
    char Name[MAX_STR_LENGTH];
}SYMBOL;

typedef struct _RULE_ENTRY
{
    char RuleName[MAX_STR_LENGTH];
    SYMBOL Selects[64][64];
}RULE_ENTRY;

static const RULE_ENTRY rule_table[] =
{
    { "A",  {
                { {0, "B"}, {1, "a"} },
                { {0, "A"}, {1, "a"} },
                { {1, "c"} }
            }
    },
    { "B",  {
                { {0, "B"}, {1, "b"} },
                { {0, "A"}, {1, "b"} },
                { {1, "d"} }
            }
    }
};

Rule *InitRules()
{
    Rule *pHead, *pRule;
    RuleSymbol **pSymbolPtr1, **pSymbolPtr2;
    int nRuleCount = sizeof(rule_table) / sizeof(rule_table[0]);

    int i, j, k;

    Rule **pRulePtr = &pHead;
    for (i = 0; i < nRuleCount; i++)
    {
        pSymbolPtr1 = &pRule->pFirstSymbol;
        for (j = 0; rule_table[i].Selects[j][0].Name[0] != '\0'; j++)
        {
            pSymbolPtr2 = pSymbolPtr1;
            for (k = 0; rule_table[i].Selects[j][k].Name[0] != '\0'; k++)
            {
                const SYMBOL *pSymbol = &rule_table[i].Selects[j][k];

                *pSymbolPtr2 = CreateSymbol();
                (*pSymbolPtr2)->isToken = pSymbol->isToken;
                if (1 == pSymbol->isToken)
                {
                    strcpy((*pSymbolPtr2)->TokenName, pSymbol->Name);
                }
                else
                {
                    (*pSymbolPtr2)->pRule = FindRule(pHead, pSymbol->Name);
                    if (NULL == (*pSymbolPtr2)->pRule)
                    {
                        printf("Init rules error, miss rule \"%s\"\n", pSymbol->Name);
                        exit(1);
                    }
                }

                pSymbolPtr2 = &(*pSymbolPtr2)->pNextSymbol;
            }
            pSymbolPtr1 = &(*pSymbolPtr1)->pOther;
        }
        pRule = pRule->pNextRule;
    }
    return pHead;
}

Rule *CreateRule(const char *pRuleName)
{
    Rule *pRule = (Rule *)malloc(sizeof(Rule));

    strcpy(pRule->RuleName, pRuleName);
    pRule->pFirstSymbol = NULL;
    pRule->pNextRule = NULL;

    return pRule;
}

RuleSymbol *CreateSymbol()
{
    RuleSymbol *pSymbol = (RuleSymbol*)malloc(sizeof(RuleSymbol));

    pSymbol->pNextSymbol = NULL;
    pSymbol->pOther = NULL;
    pSymbol->isToken = -1;
    pSymbol->TokenName[0] = '\0';
    pSymbol->pRule = NULL;

    return pSymbol;
}

Rule *FindRule(Rule *pHead, const char *RuleName)
{
    Rule *pRule;
    for (pRule = pHead; pRule != NULL; pRule = pRule->pNextRule)
    {
        if (0 == strcmp(pRule->RuleName, RuleName))
        {
            break;
        }
    }
    return pRule;
}

void PrintRule(Rule *pHead)
{
    //TODO
}