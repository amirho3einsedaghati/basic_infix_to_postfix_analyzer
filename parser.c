/* =============================================== Parser Module ================================================ */

/* =============================================== description ================================================== */

/*

this grammar shows parsing :

Expr   -> Expr + term | Expr – term | term
term   -> term * factor | term / factor | factor
factor -> power ↑ factor | power
power  -> digit | (Expr)
digit  -> 0 | 1 | 2 | …| 9

this grammar without leftRecursion :

Expr    ->    term rest

rest    ->  +  term {print('+')} rest
        ->  -  term {print('-')} rest
        ->  *  term {print('*')} rest
        ->  /  term {print('/')} rest
        ->  ^  term {print('^')} rest
        ->  (Expr) rest
        -> epsilon

term    -> 0 {print('0')}
        -> 1 {print('1')}
        -> 2 {print('2')}
.....
        -> 9 {print('9')}

*/


/* =============================================== Implementation ================================================ */

#include <stdio.h>
#include "lexical_analyzer.h"

int lookahead;
int num;

void match(t)
{
    int t
    if(lookahead == t){
        lookahead = lexan();
    else
        printf("something went wrong");
    }
}

void parseExpr()
{
    parseTerm();
    parseRest();
}

void parserTerm()
{
    match(num);
    print("%d",tokenVal);
}


void parseRest()
{
    while(1){
        if(lookahead == "+"){
            match("+");
            parseTerm();
            print("+");
         }

        else if(lookahead == "-"){
            match("-");
            parseTerm();
            print("-");
         }
        else if(lookahead == "*"){
            match("*");
            parseTerm();
            print("*");
         }
        else if(lookahead == "/"){
            match("/");
            parseTerm();
            print("/");
         }
        else if(lookahead == "^"){
            match("^");
            parseTerm();
            print("^");
         }
        else if(lookahead == "("){
            match("(");
            parseExpr();
         }
        else if(lookahead == ")"){
            match(")");
        }
         else
             return
    }
}



