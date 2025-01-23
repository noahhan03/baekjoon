#include<stdio.h>
#include<string.h>

int main()
{
    char str[200];
    int st=0,en,chk=1;
    scanf("%s",str);
    getchar();
    en=strlen(str)-1;
    while(st<=en){
        if(str[st]!=str[en]){
            chk=0;
        }
    }
    if(chk)printf("1\n");
    else printf("0\n");
}