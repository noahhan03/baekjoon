#include<iostream>

using namespace std;

const int mod=1e9+7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,p,a,b;
    cin >> n;
    if(n==0){
        cout << "0";
        return 0;
    }
    else if(n==1){
        cout << "1";
        return 0;
    }
    else if(n==2){
        cout <<"1";
        return 0;
    }
    a=0;
    b=1;
    p=1;
    for (int i=3;i<=n;i++){
        a=b%mod;
        b=p%mod;
        p=(a+b)%mod;
    }
    cout << p;
}