#include<iostream>
#include<string>

typedef long long ll;

using namespace std;

ll N; // 문자열 길이
ll K[1000001];
ll CK[1000001];
ll OCK[1000001];
ll mod=1000000007;

ll p(ll a,ll b)
{
    ll chk=1;
    for(ll i=b;i>=1;i--)chk*=a;
    return a;
}

int main()
{
    string S; //확인할 문자열
    cin >> N >> S;
    ll ans=0;
    for(ll i=N-1;i>=0;i--){
        K[i]=K[i+1];
        CK[i]=CK[i+1];
        OCK[i]=OCK[i+1];
        if(S[i]=='O') OCK[i]=(OCK[i]+CK[i])%mod;
        if(S[i]=='C') CK[i]=(CK[i]+K[i])%mod;
        if(S[i]=='K') K[i]=(K[i]+1)%mod;
        if(S[i]=='R') ans=(ans+p(2,i+1)*OCK[i])%mod;
    }
    cout << ans;
}