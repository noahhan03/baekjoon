#include<iostream>

typedef long long ll;

using namespace std;

ll arr[100010];
pair<int,int> big_small[400040]; // big, small
int big,small;

void mer(int I){
    if(big_small[I<<1].first<big_small[I<<1|1].first){
        big_small[I].first=big_small[I<<1|1].first;
    }
    else{
        big_small[I].first=big_small[I<<1].first;
    }
    if(big_small[I<<1].second<big_small[I<<1|1].second){
        big_small[I].second=big_small[I<<1].second;
    }
    else{
        big_small[I].second=big_small[I<<1|1].second;
    }
}

void build(int l,int r,int I){
    if(l==r){
        big_small[I].first=arr[l];
        big_small[I].second=arr[l];
        return ;   
    }
    int m=l+r>>1;
    build(l,m,I<<1);
    build(m+1,r,I<<1|1);
    mer(I);
}

void query(int l,int r,int x, int y ,int I){
    if(y<l || r<x)return ;
    if(x<=l && r<=y){
        if(big<big_small[I].first){
            big=big_small[I].first;
        }
        if(small>big_small[I].second){
            small=big_small[I].second;
        }
        return ;
    }
    int m=l+r>>1;  
    query(l,m,x,y,I<<1);
    query(m+1,r,x,y,I<<1|1);
}

void update(int l,int r,int x,int y,int I ,int d){
    if(y<l || r<x)return ;
    if(x<=l && r<=y){
        big_small[I].first=d;
        big_small[I].second=l;
        return ;
    }
    int m=l+r>>1;
    update(l,m,x,y,I<<1,d);
    update(m+1,r,x,y,I<<1|1,d);
    mer(I);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,m;
    cin >> n >> m;
    for(ll i=1;i<=n;i++)
    {
        cin >> arr[i];
    }
    build(1,n,1);
    for(ll i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        big=0;
        small=2e9;
        query(1,n,a,b,1);
        cout<<small <<" "<<big<<"\n";
    }
}