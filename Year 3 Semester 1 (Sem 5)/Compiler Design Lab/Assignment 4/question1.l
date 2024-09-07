%{
#include<stdio.h>
%}
sign [+-]?
digit [0-9]+
exp ([eE]{sign}{digit})
%%
\+?{digit} printf("Number is positive");
\-{digit} printf("Number is negative");
{sign}{digit}?\.{digit}? printf("Number is real");
{sign}{digit}(\.{digit}?)?{exp} printf("Number is exponential");
%%
int yywrap()
{
    return 1;
}
int main()
{
    char myString[100];
    fgets (myString, sizeof(myString), stdin);
    yy_scan_string(myString);
    yylex ();
}
