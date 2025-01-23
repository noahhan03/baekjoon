#include<stdio.h>

int main(){
    double p,q,r;
    double l1, l2, r1, r2;
    scanf("%f %f %f",&p,&q,&r);
    l1=p*p;
    l2=p*q;
    r1=q*r;
    r2=r*r;
    
    if((l1+l2)==(r1+r2)){
        if(p==q && q==r){
            double x=sqrt(10);
            // cout.fixed;
            // cout.precision(4);
            printf("%.4ld",x*r2);
            // cout<< x*r2;
        }
        else if(p==r){

            printf("%.4ld",p*(p+q)*2);
        }
        else if(p==q || q==r){
            printf("%.4ld",q*(p+q)*2);
        }
    }
    else printf("0");
}