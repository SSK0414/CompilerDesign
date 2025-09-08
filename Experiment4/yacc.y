%{
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int yylex();
int yyerror(const char *s);

#define YYSTYPE double
%}

%token NUMBER
%left '+' '-'
%left '*' '/'
%right UMINUS

%%
lines
    : lines expr '\n'   { printf("%g\n", $2); }
    | lines '\n'
    | /* empty */
    ;

expr
    : expr '+' expr     { $$ = $1 + $3; }
    | expr '-' expr     { $$ = $1 - $3; }
    | expr '*' expr     { $$ = $1 * $3; }
    | expr '/' expr     { $$ = $1 / $3; }
    | '(' expr ')'      { $$ = $2; }
    | '-' expr %prec UMINUS { $$ = -$2; }
    | NUMBER
    ;
%%

int yylex() {
    int c;

    // skip spaces
    while ((c = getchar()) == ' ');

    // number literal
    if (c == '.' || isdigit(c)) {
        ungetc(c, stdin);
        if (scanf("%lf", &yylval) != 1) return 0;
        return NUMBER;
    }

    return c; // operators and newline
}

int yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
    return 1;
}

int yywrap() {
    return 1;
}

int main() {
    return yyparse();
}
