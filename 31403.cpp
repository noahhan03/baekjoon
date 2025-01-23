#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int a,b,c,n;
    int cnt=0;
    cin >> a >> b >> c;
    cout << a+b-c<<"\n";
    n=b;
    while(n>0){
        n/=10;
        cnt++;
    }
    a=a*pow(10,cnt)+b;
    cout << a-c;
}