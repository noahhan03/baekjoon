#include<iostream>
#include<string>
using namespace std;

int dp[2010][2010];


int main(){
    string s1, s2;
    cin >> s1 >> s2;
    int alen=s1.length();
    int blen=s2.length();
    for(int i=1;i<=alen;i++){
        for(int j=1;j<=blen;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout << dp[alen][blen];
}