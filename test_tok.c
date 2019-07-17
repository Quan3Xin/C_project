#include <stdio.h>
#include <string.h>
/*
int main()
{
    char  a[]= "hello,world!";
    char *b = strtok(a, ",");
    while(b != NULL){
        printf("%s\n", b);
        b = strtok(NULL, b);
    }

    return 0;
} */
int main()
{
    char s[]="33,2019/3/18 9:54,0,4 29,2019/3/18 9:54,0,0 27,2019/18 9:54,0,0";
    const char *key=",";
    char *p;
    p=strtok(s, ",");
    while(p)
    {
        printf("%s\n",p);
        p=strtok(NULL,key);
    }
    printf("\n");
    return 0;
}
