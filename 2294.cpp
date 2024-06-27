#include<iostream>
#include<vector>
using namespace std;

int dp[10010];

int main(){
    int n,k,cnt=0;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    //reset
    for(int i=1;i<=k;i++)dp[i]=12345;
    for(int i=0;i<n;i++){
        // cout << "i : "<<i <<" 동전 type : "<<arr[i]<<"\n";
        for(int j=arr[i];j<=k;j++){
            // cout << "j : "<<j<<" dp[j] : "<<dp[j]<<" dp[j-arr[i]]+1 : " << dp[j-arr[i]]+1<<"\n";
            // 최솟값 만들수있으면 갱신
            dp[j]=min(dp[j],dp[j-arr[i]]+1);
        }
    }
    if(dp[k]==12345)cout<<"-1";
    else 
        cout << dp[k];
}