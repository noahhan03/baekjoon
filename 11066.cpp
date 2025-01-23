#include<iostream>

using namespace std;

int dp[502][502];
int co[502];
int sum[503]; //누적합

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int min,z;
    int t,k,res;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        cin >> k;
        cin >> co[1];
        sum[1]=co[1];
        for(int j=2;j<=k;j++){
            cin>>co[j];
            sum[j]=sum[j-1]+co[j];
        }
        for(int sz=0;sz<k;sz++){
            for(int st=1;st+sz<=k;st++)
            {   
                if(sz==0)dp[st][st+sz]=0;
                else {
                    dp[st][st+sz]=sum[st+sz]-sum[st-1];
                    min=dp[st][st]+dp[st+1][st+sz];
                    for(int i=st;i<st+sz;i++){
                        z=dp[st][i]+dp[i+1][st+sz];
                        if(min>z)min=z;
                    }
                    dp[st][st+sz]+=min;
                }
            }
        }
        cout << dp[1][k]<<"\n";
    }
}