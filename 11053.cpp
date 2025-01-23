#include<iostream>

using namespace std;

int dp[1001];
int ar[1001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int max,maxx;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> ar[i];
    }
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=1;
        max=1;
        for(int j=1 ; j<i;j++){
            if(ar[i]>ar[j] && max<(dp[j]+1)){
                max=dp[j]+1;
                dp[i]=max;
            }
        }
    }
    maxx=dp[1];
    for(int i=2;i<=n;i++){
        if(maxx<dp[i])maxx=dp[i];
    }
    cout <<maxx;
}