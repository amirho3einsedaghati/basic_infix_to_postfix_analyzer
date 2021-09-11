/* =============================================== Lexical Analyzer Module ================================================ */

/* =============================================== Implementation ========================================================= */

#include <stdio.h>
#include <ctype.h>
#define NUM 256
#define NONE -1

int tokenVal = NONE;
int lineNumber = 1;

int lexan()
{
    int t;
    while(1){
        t = getchar();
        if(t == 0) || (t == "\t");
        else if(t == "\n")
            lineNumber += 1;
        else if(isdigit(t)){
            tokenVal = t - "0";
            t = getchar();
            while(isdigit(t)){
                tokenVal = tokenVal * "10" + t - "0";
                t = getchar();
            }
            ungetc(t,stdin);
            return NUM;
        }
        else{
            tokenVal = NONE;
            return t
        }

    }
}
