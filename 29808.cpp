#include<stdio.h>
int main()
{
    int s, ch=0, ck, a[99999], cnt=0;
    scanf("%d",&s);
    if(s==0) return !printf("1\n0 0");
    for(int i=0;i<=200;i++){ // 국여-영어 차
        for(int j=0;j<=200;j++){ //수학-탐구차
            int ke, ms;
            for(int p=0;p<2;p++){ // 국-영 508 108
                for(int q=0;q<2;q++){ //수-탐 212 305
                    if(p) ke=i*508; else ke=i*108;
                    if(q) ms=j*212; else ms=j*305;
                    if((ke+ms)*4763==s) ch++, a[cnt++]=i, a[cnt++]=j;
                }
            }
        }
    }
    ck=ch;
    if(ch) for(int i=0;i<ch;i++){
        if(a[i*2]==a[i*2+2] && a[i*2+1]==a[i*2+3]) ck--;
    }
    printf("%d\n", ck); 
    if(ck) for(int i=0;i<ch;i++){
        if(a[i*2]==a[i*2+2] && a[i*2+1]==a[i*2+3]) ck--;
        else printf("%d %d\n", a[i*2], a[i*2+1]);
    }
}