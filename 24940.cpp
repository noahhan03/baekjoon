#include<iostream>

using namespace std;

int dp[82][82];
int dp_add[82][82];
int np[82]; //누적곱
int na[82]; //누적합

int rrr(int a,int b) //부호 다르면 1 , 같으면 0
{
    if((a > 0 && b <0) || (a < 0 && b > 0))return 1;
    else return 0;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,arr[82],chk=0; //np는 누적곱,na는 누적합
    int min;
    int kk;
    cin >> n;
    cin >> arr[1];
    np[1]=arr[1];
    na[1]=arr[1];
    if(arr[1]>=0)chk=1;
    for(int i=2;i<=n;i++)
    {
        cin >> arr[i]; 
        np[i]=np[i-1]*arr[i];
        na[i]=na[i-1]+arr[i];
        if(arr[i]<0)chk=1;
    } 
    for(int sz=0;sz<n;sz++){
        for(int st=1;st+sz<=n;st++){
            if(sz==0)dp[st][st+sz]=0;
            else {
                min=0;
                for(int i=st;i<st+sz;i++){
                    int a=na[st+sz]-na[i];
                    int b=na[i]-na[st-1];
                    kk=dp[st][i]+dp[i+1][st+sz];
                    if(rrr(a,b)){
                        kk=kk+a*b;
                    }
                    if(min>kk)min=kk;
                }
                dp[st][st+sz]=min;
            }
        }
    }
    if(chk)cout << dp[1][n];
    else cout << arr[1]*(na[n]-na[1]);
}