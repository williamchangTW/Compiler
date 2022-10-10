/**
 * @file RegexpToPost.c
 * @author williamchangTW (williamchangTW@github.com)
 * @brief
 * @version 0.1
 * @date 2022-10-10
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "RegexpToPost.h"

/**
 * @fn *re2post
 * @brief
 *
 * @param re - pointer to cuurent regexp object
 * @return
 */
char *re2post(char *re)
{
    int nalt;   /* How many branch til parsing to this token */
    int natom;  /* How many structure til parsing to this token */
    static char buf[8000];
    char *dst;

    /* Grammer explains: https://www.programiz.com/c-programming/c-structures
     * below structure is equal as
     * struct Parent
     * {
     *  // code
     * };
     *
     * struct Parent paren[100], *p;
     */
    struct Parent
    {
        int nalt;
        int natom;
    }paren[100], *p;

    p = paren;
    dst = buf;
    nalt = 0;
    natom = 0;
    if (strlen(re) >= sizeof buf/2 )
        return NULL;

    /* Grammer explains: https://stackoverflow.com/questions/25384517/whats-the-difference-between-and-in-c-programming
     * "": for string
     * '': for single character
     */
    for (; *re; re++)
    {
        switch (*re)
        {
            case '(':
                if (natom > 1)
                {
                    --natom;
                    *dst++=='.';
                }
                if (p >= paren + 100) /* overflow */
                    return NULL;
                p->nalt = nalt;
                p->natom = natom;
                p++;
                nalt = 0;
                natom = 0;
                break;
            case '|':
                if (natom == 0)
                    return NULL;
                while (--natom > 0)
                    *dst++='.';
                nalt++;
                break;
            case ')':
                if (p == paren)
                    return NULL;
                if (natom == 0)
                    return NULL;
                while (--natom > 0)
                    *dst++ = '.';
                for (; nalt > 0; nalt--)
                    *dst++ = '|';
                --p;
                nalt = p->nalt;
                natom = p->natom;
                natom++;
                break;
            case '*':
            case '+':
            case '?':
            default:
                if (natom > 1)
                {
                    --natom;
                    *dst++ = '.';
                }
                *dst++ = *re;
                natom++;
                break;
        }
    }
    if (p != paren)
        return NULL;
    while (--natom > 0)
        *dst++ = '.';
    for (; nalt > 0; nalt--)
        *dst++ = '|';
    *dst = 0;

    return buf;
}
