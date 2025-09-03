#include <stdio.h>
#define SIZE 50

int main() {
    char table[3][4][5]={{"A","","",""},{"Bi","","",""},{"","A+","A*","e"}};
    char stack[SIZE]="$S", buf[SIZE];
    printf("Enter: "); scanf("%s", buf);

    int top=1, ip=0, k; char *rule;
    printf("stack \t\t buffer\n");

    while (buf[ip]) {
        printf("%s \t\t %s", stack, buf+ip);

        if ('A'<=stack[top] && stack[top]<='Z') {   // Non-terminal
            int i=(stack[top]=='S') ? 0 : (stack[top]=='A') ? 1 : 2;
            int j=(buf[ip]=='i') ? 0 : (buf[ip]=='+') ? 1 : (buf[ip]=='*') ? 2 : 3;
            rule=table[i][j];

            if (!rule) { printf("\nFAILED (invalid symbol).\n"); break; }
            if (!*rule){ printf("\nFAILED (no production rule).\n"); break; }

            if (*rule=='e') stack[top--]=0;
            else { for (k=0;rule[k];k++) stack[top+k]=rule[k]; stack[top+k]=0; top+=k-1; }
            printf("\t (replace %s)\n", rule);

        } else {                                    // Terminal
            if (stack[top]==buf[ip]) {
                if (stack[top]=='$'){ printf("\nSUCCESS.\n"); break; }
                stack[top--]=0; ip++; printf("\t (pop)\n");
            } else { printf("\nFAILED (not-equal).\n"); break; }
        }
    }
}
