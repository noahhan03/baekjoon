#include<iostream>

using namespace std;

const int mod=10007;
int dp[1001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,a,b,p;
    dp[1]=1;
    dp[2]=2;
    cin >> n;
    for(int i=3;i<=n;i++)
    {
        dp[i] = (dp[i-1] + dp[i-2] )%mod;
    }
    cout <<dp[n];
}