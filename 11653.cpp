#include<iostream>
#include<math.h>
 
#define ll long long

using namespace std;


int main(){

    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n;
    cin >> n; 
    ll x= n;
    for(ll i=2;i<=x;i++){
        if(n%i==0){
            cout << i<<"\n";
            n/=i;
            i--;
        }
    }
}

