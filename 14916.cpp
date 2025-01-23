#include<iostream>

using namespace std;

int dp[100001];

int main(){
    int n;
    cin >> n;
    dp[2]=1;
    dp[4]=2;
    dp[5]=1;
    for(int i=6;i<=n;i++){
        if(dp[i-2]){
            if(dp[i-5]){
                dp[i]=min(dp[i-2],dp[i-5])+1;
            }
            else dp[i]=dp[i-2]+1;
        }
        else if(dp[i-5])dp[i]=dp[i-5]+1;
    }
    if(dp[n])cout << dp[n];
    else cout <<"-1";
}