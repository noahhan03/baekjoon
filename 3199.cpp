#include<iostream>
#include<math.h>
using namespace std;

int main(){
    float p,q,r;
    float l1, l2, r1, r2;
    cin >> p >> q >> r;
    l1=p*p;
    l2=p*q;
    r1=q*r;
    r2=r*r;
    if((l1+l2)==(r1+r2)){
        if(p==q && q==r){
            float x=sqrt(10);
            // cout.fixed;
            // cout.precision(4);
            printf("%.4f",x*r2);
            // cout<< x*r2;
        }
        else if(p==r){

            printf("%.4f",p*(p+q)*2);
        }
        else if(r==q || p==q){
            printf("%.4f",q*(p+q)*2);
        }
        else cout<<"0";
    }
    else cout<<"0";
}