#include<iostream>

typedef long long ll;
using namespace std;

ll arr[100010];
ll seg[400040];
int n,q;

void mer(int I){
    seg[I]=seg[I<<1]+seg[I<<1|1];
}
void build(int l,int r,int I){
    if(l==r){
        seg[I]=arr[l];
        return ;
    }
    int m=l+r>>1;
    build(l,m,I<<1);
    build(m+1,r,I<<1|1);
    mer(I);
}

ll query(int l,int r, int x ,int y ,int I){
    if(y<l || x>r)return 0;
    if(x<=l && r<=y){
        return seg[I];
    }
    int m=l+r>>1;
    return query(l,m,x,y,I<<1)+query(m+1,r,x,y,I<<1|1);
}

void update(int l,int r, int x ,int y ,int I,int d){
    if(y<l || x>r)return ;
    if(x<=l && r<=y){
        seg[I]=d;
        return ;
    }
    int m=l+r>>1;
    update(l,m,x,y,I<<1,d);update(m+1,r,x,y,I<<1|1,d);
    mer(I);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    build(1,n,1);
    for(int i=0;i<q;i++){
        ll a,b;
        cin >> a >> b;
        if(a>b){
            ll t=a;
            a=b;
            b=t;
        }
        cout<<query(1,n,a,b,1)<<'\n';
        cin >> a >> b;
        update(1,n,a,a,1,b);
    }
}