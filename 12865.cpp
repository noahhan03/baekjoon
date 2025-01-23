#include<iostream>

using namespace std;

int dp[100001][101]; //dp[i][j] - i배낭 무게 , j번째까지 확인
int maxx(int a,int b)
{
    if(a>b) return a;
    else return b;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k,wei[101],val[101];
    int max=0;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> wei[i] >> val[i];
    }
    for(int i=0;i<=k;i++)
    {
        for(int j=0;j<n;j++){
            if(i==0)dp[i][j]=0;
            else if(i >= wei[0] && j==0)dp[i][0]=val[0];
            else if(j == 0) dp[i][0] = 0;
            else {dp[i][j]=maxx( dp[i][j-1], dp[i-1][j]);
                
            if(i>=wei[j] ){
                dp[i][j]=maxx(dp[i][j], dp[ i-wei[j] ][j-1]+val[j]);
            }}
            if(max<dp[i][j])max=dp[i][j];
        }
    }
    cout << max;
}