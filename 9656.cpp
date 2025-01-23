#include<iostream>

using namespace std;

bool dp[1010][2];

int main(){
    // 1 이면 SK , 0이면 CY
    int n;
    cin >> n;
    dp[1][1]=0;
    dp[2][0]=1;
    dp[2][1]=1;
    dp[0][0]=0;
    dp[0][1]=0;
    dp[1][0]=0;
    dp[3][1]=0;
    dp[3][0]=0;
    for(int i=4;i<=n;i++){
        for(int j=0;j<=1;j++){
            if(dp[i-3][j] || dp[i-1][j])dp[i][!j]=false;
            else dp[i][j]=true;
        }
    }
    if(dp[n][1])cout <<"SK";
    else cout <<"CY";
}