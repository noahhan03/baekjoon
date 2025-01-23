#include<iostream>
using namespace std;

int arr[100010];
int dp[100010]; // dp[i] 배열의 처음부터 j 까지 봤을 때 최소

int main(){
    int n;
    int result;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    dp[0]=arr[0];
    result=dp[0];
    for(int i=1;i<n;i++){
        if((dp[i-1]+arr[i])>arr[i])dp[i]=dp[i-1]+arr[i];
        else dp[i]=arr[i];
        if(dp[i]>result)result=dp[i];
    }
    cout << result;
}