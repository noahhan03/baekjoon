#include<iostream>
using namespace std;

int main(){
    long long a,b,x,y;
    cin >> b >> a;
    if(a<b){
        long long t=a;
        a=b;
        b=t;
    }
    if(a>0 && b<0){
        if(abs(a)>abs(b)){
            b=-b;
            b++;
        }
        else if(abs(a)==abs(b)){
            a=0;
            b=0;
        }
        else {
            a=-a;
            a--;
        }
    }
    x=a-b+1;
    y=a+b;
    // cout << "x : "<<x <<" y : "<<y<<endl;
    cout << x*y/2;
}