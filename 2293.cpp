#include<iostream>
#include<vector>
using namespace std;

int dp[10010];
int arr[101];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k,cnt=0;
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=arr[i];j<=k;j++){
            dp[j]=dp[j-arr[i]]+dp[j];
        }
    }
    cout << dp[k];
}