#include<iostream>
using namespace std;

int dp[1010][3]; 

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin >> dp[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        dp[i][0] += min(dp[i-1][1],dp[i-1][2]);
		dp[i][1] += min(dp[i-1][0],dp[i-1][2]);
		dp[i][2] += min(dp[i-1][0],dp[i-1][1]);
    }
    if(dp[n-1][0]<dp[n-1][1]){
        if(dp[n-1][0]<dp[n-1][2])cout<<dp[n-1][0];
        else cout << dp[n-1][2];
    }
    else if(dp[n-1][1]<dp[n-1][2])cout << dp[n-1][1];
    else cout << dp[n-1][2];
}