#include<iostream>
#include<vector>

typedef long long ll;

using namespace std;


ll v[100010]; // dp[i] 2 X i 우리에 사자 가두는 경우의 수 
// dp[i] = dp[i-1] 
// dp[1] - 



void dp(ll n){
    v[1]=3;
    v[2]=7;
    for(ll i=3;i<=n;i++){
        v[i]=(v[i-1]*2 + v[i-2])%9901;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n;
    cin >> n;
    dp(n);
    cout << v[n];
}