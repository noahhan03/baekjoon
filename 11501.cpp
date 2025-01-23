#include<iostream>
#include<vector>

using namespace std;

typedef long long ll;

int main(){
    ll T;
    ll Psum=0;
    ll mv;
    cin >> T;
    for(ll i=0;i<T;i++){
        ll date,tmp;
        ll s_v[1000000];
        cin >> date;
        Psum=0;mv=0;
        for(ll j=0;j<date;j++){
            cin >> s_v[j];
        }
        for(ll j=(date-1);j>=0;j--){
            if(s_v[j]<mv){
                Psum+=(mv-s_v[j]);
            }
            else {
                mv=s_v[j];
            }
        }
        cout << Psum <<"\n";
    }
}