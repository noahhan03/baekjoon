#include<iostream>

typedef long long ll;

using namespace std;



ll arr[1000010];
ll seg[4000010];


void mer(ll I){
    seg[I]=seg[I<<1]+seg[I<<1|1];
}
void build(ll l,ll r, ll I ){
    if(l==r){
        seg[I]=arr[l];
        return ;
    }
    ll m=l+r>>1;
    build(l,m,I<<1);
    build(m+1,r,I<<1 | 1);
    mer(I);
}

ll query(ll l,ll r, ll x ,ll y , ll I){
    if(l>y || r<x)return 0;
    if(x<=l && r <=y)return seg[I];
    ll m=l+r>>1;
    return query(l,m,x,y,I<<1)+query(m+1,r,x,y,I<<1|1);
}

void update(ll l,ll r, ll x ,ll y , ll I, ll d){
    if(l>y || r<x)return ;
    if(x<=l && r <=y){
        seg[I]=d;
        return ;
    }
    ll m=l+r>>1;
    update(l,m,x,y,I<<1,d);
    update(m+1,r,x,y,I<<1|1,d);
    mer(I);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,m,k;
    cin >> n >> m >> k;
    for(ll i=1;i<=n;i++){
        cin >> arr[i];
    }
    // cout << "arr 입력";
    build(1,n,1);
    for(ll i=0;i<m+k;i++){
        ll a,b,c;
        cin >> a >> b >> c;
        if(a==1){ //b번째 c로 update 
            update(1,n,b,b,1,c);
        }
        else { // b ~ c 출력 
            cout << query(1,n,b,c,1) <<"\n";
        }
    }
}