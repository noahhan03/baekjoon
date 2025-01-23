#include<iostream>
#include<vector>

#define ll long long

using namespace std;

ll n;
vector<pair<ll,ll>> v;

int main(){
    cin >> n;
    for(ll i=0;i<n;i++){
        ll a,b;
        cin >> a >> b;
        v.emplace_back(a,b);
    }
}