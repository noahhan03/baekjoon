#include<iostream>

using namespace std;

int dp[100001][1001]; //dp[i][j] - i배낭 무게 , j번째까지 확인
int maxx(int a,int b)
{
    if(a>b) return a;
    else return b;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k[1001],wei[1001],val[1001],m;
    int max=0,result,max_k,min_k,minmin=1234;
    float max_e=0,may,arrr[1000001];
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> wei[i] >> val[i];
    }
    cin >> k[0];
    min_k=k[0];
    max_k=k[0];
    for(int i=1;i<m;i++){
        cin >> k[i];
        if(min_k>k[i])min_k=k[i];
        if(max_k<k[i])max_k=k[i];
        arrr[k[i]]=i;
    }
    max=0;
    for(int i=0;i<=max_k;i++)
    {
        for(int j=0;j<n;j++){
            if(i==0)dp[i][j]=0;
            else if(i >= wei[0] && j==0)dp[i][0]=val[0];
            else if(j == 0) dp[i][0] = 0;
            else {
                dp[i][j]=maxx( dp[i][j-1], dp[i-1][j]);
                    
            if(i>=wei[j] ){
                dp[i][j]=maxx(dp[i][j], dp[ i-wei[j] ][j-1]+val[j]);
            }
            
            }
            if(max<dp[i][j])max=dp[i][j];
        }
        may=(float)max/i;

        if(max_e < may && i>=min_k){
            if(max_e==may && minmin>arrr[i]){
                minmin=arrr[i];
                result = minmin +1;
            }
            else {
                max_e=may;
                result=arrr[i]+1;
            }
        }
    }
        
    
    cout << result;
}