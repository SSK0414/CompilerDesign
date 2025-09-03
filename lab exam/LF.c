#include <stdio.h>
#include <string.h>

#define SIZE 50

int main(){
    char buf[SIZE], r1[SIZE], r2[SIZE], prefix[SIZE];

    printf("Enter the production rules (ex.. A -> rule1|rule2): \n A-> ");
    scanf("%s", buf);

    sscanf(buf, "%[^|]|%s", r1, r2);

    printf("---\n");

    int i = 0, k = 0;
    while (r1[i] && r1[i] == r2[i]){
        prefix[k++] = r1[i++];
    }
    prefix[k] = '\0';

    if (!r1[i] && !r2[i]){
        printf("A -> %s\n", prefix);
    } else {
        printf("A -> %sA' \n", prefix);
        printf("A -> %s", r1+i);
        if (* (r2+i)) printf("|%s",r2+i);
        printf("\n");
    }
    return 0;
}
