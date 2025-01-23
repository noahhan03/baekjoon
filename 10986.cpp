#include<iostream>
#include<vector>

using namespace std;

long long n,m; 
long long x;
long long re[1010];
long long sum=0;
long long ans=0;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    cin >> x;
    sum=x;
    re[0]++;
    re[sum%m]++;
    for(int i=1;i<n;i++){
        cin >> x;
        sum= sum +x ;
        re[sum%m]++;
    }

    for(int i=0;i<=m;i++){
        if(re[i]>=2){
            ans+= (re[i]-1)*re[i]/2;
        }
    }
    if(0){
        if(x%m==0)cout <<"1";
        else cout << "0";
    }
    else {
        cout << ans ;
    }
}