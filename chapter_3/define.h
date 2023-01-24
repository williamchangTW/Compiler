#ifndef _DEFINE_H
#define _DEFINE_H

typedef enum
{
    /* end of file */
    ENDFILE,
    /* error */
    ERROR,
    /* keyword */
    IF,             //if
    THEN,           //then
    ELSE,           //else
    END,            //end
    REPEAT,         //repeat
    UNTIL,          //until
    READ,           //read
    WRITE,          //write
    /* identity pattern */
    ID,
    /* integer */
    NUM,
    /* pattern */
    ASSIGN,         //:=
    EQ,             //=
    LT,             //<
    PLUS,           //+
    MINUS,          //-
    TIMES,          //*
    OVER,           ///
    LPAREN,         //(
    RPAREN,         //)
    SEMI,           //;
    /* comment */
    COMMENT         //{...}
}TokenType;

#endif