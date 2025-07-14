%{
#include <stdio.h>
int words = 0, digits = 0, specials = 0;
%}

%%
[ \t\n]+          ; // Ignore whitespace
[a-zA-Z]+         { words++; }
[0-9]+            { digits++; }
.                 { specials++; }
%%

int yywrap() { return 1; }

int main() {
    yylex();
    printf("Words: %d\nDigits: %d\nSpecial Characters: %d\n", words, digits, specials);
    return 0;
}
