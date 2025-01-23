#include<stdio.h>
//0 - 국어, 1- 수학, 2-영어, 3-탐구 , 4- 제2외국어
int a[6];
int main()
{
    int t;
    int s=0;
    scanf("%d",&t);
    for(int i=0;i<t;i++) 
    {
        scanf("%d",&a[i]);
    }
    
    if(a[0]>a[2]){
            s=s+(a[0]-a[2])*508;
    }
    else {
            s=s+(a[2]-a[0])*108;
    }
    
    
    if(a[1]>a[3]) s=s+(a[1]-a[3])*212;
    else s=s+(a[3]-a[1])*305;

    if(t==5)s=s+a[4]*707;
    s=s*4763;
    printf("%d",s);
    return 0;
}