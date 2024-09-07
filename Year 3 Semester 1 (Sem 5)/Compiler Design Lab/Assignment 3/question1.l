%{
#include <stdio.h>

int vowelCount = 0;
int consonantCount = 0;
%}

%%
[aAeEiIoOuU]   { vowelCount++; }
[a-zA-Z]       { consonantCount++; }
.              ; 

%%

int main() {
    yy_scan_string("Hello, World!");

    yylex();

    printf("Vowel count: %d\n", vowelCount);
    printf("Consonant count: %d\n", consonantCount);

    return 0;
}
