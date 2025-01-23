#include<iostream>

using namespace std;

const int ran=1e6;
int dp[ran + 4];


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int min;
    cin >> n;
    dp[1]=0;
    dp[2]=1;
    for(int i=3;i<=n;i++){
        min=dp[i-1]+1;
        if(i%2==0 && min>(dp[i/2]+1) )min=dp[i/2]+1;
        if(i%3==0 && min>(dp[i/3]+1) )min=dp[i/3]+1;
        dp[i]=min;
    }
    cout << dp[n];
}