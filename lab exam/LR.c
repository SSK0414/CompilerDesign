#include <stdio.h>
#include <string.h>

int main(){
    char buf[50], r1[50], r2[50];
    printf("Enter a prodcution rule (e.g., S->rule1|rule2): \n A -> ");
    scanf("%s", buf);

    sscanf(buf, "%[^|]|%s", r1, r2);

    printf("---\n");

    char *a = (r1[0] == 'A') ? r1+1 : r2+1;
    char *b = (r1[0] == 'A') ? r2 : r1;

    if (r1[0] != 'A' && r2[0] != 'A'){
        printf("no left recursion\n");
    } else {
        printf(" A -> %sA' \n", b);
        printf(" A -> %sA|epsilon \n ", a);
    }
    return 0;
}