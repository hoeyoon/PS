#include <stdio.h>
#define LEN_INPUT 11

int main(void) {
    char s1[LEN_INPUT];
    scanf("%s", s1);
    char *p = s1;
    while(*p != '\0'){
        printf("%c\n", *p);
        p++;
    }
    return 0;
}
