#include<iostream>
using namespace std;


int befN,befK;

int sol(){
    int k,n;
    cin >> k >> n;
    //k층에 n호에는 몇 명
    //a층의 b호에 살려면 자신의 아래(a-1)층의 1호부터 b호까지 사람들의 수의 합만큼 사람들을 데려와 살아야 한다
    int dp[15][15];
    for(int i=0;i<n;i++)dp[i][0]=1;
    for(int i=0;i<n;i++)dp[0][i]=i+1;
    // if(dp[n][k])return dp[n][k];
    for(int i=1;i<=k;i++){
        for(int j=1;j<n;j++){
            dp[i][j]=dp[i][j-1]+dp[i-1][j];
        }
    }
    return dp[k][n-1];
}
int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cout <<sol()<<"\n";
	}

		
	return 0;
}