#include<iostream>
#include<math.h>
using namespace std;

int main(){
    double p,q,r;
    double l1, l2, r1, r2;
    cin >> p >> q >> r;
    l1=(p+q)*(p+q);
    l2=p*p;
    r1=(q+r)*(q+r);
    r2=r*r;
    if((l1+l2)==(r1+r2)){
        if(p==r && r==q){
        double x=sqrt(10);
        cout.precision(4);
        cout << l2*x;
        }
        else if(p==r){
            cout.precision(4);
            cout<<fixed;
            cout << p*(p+q)*2;
        }
        else if(r==q || q==p){
            cout.precision(4);
            cout<<fixed;
            cout << q*(p+q)*2;
        }
        else cout<<"0";
    }
    else {
        cout <<"0";
    }
    

    // else if(p==q || r==q){
    //     cout.precision(4);
    //     cout << (p+r)*(p+r)*2;
    // }
}