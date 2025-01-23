#include<iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    int dp[12];
    dp[1]=1;
    dp[2]=2;
    dp[3]=4;
    dp[4]=7;
    for(int i=5;i<11;i++){
        dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
    }
    for(int i=0;i<t;i++){
        int cn;
        cin >> cn;
        cout <<dp[cn]<<"\n";
    }
}