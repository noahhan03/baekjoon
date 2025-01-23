#include<iostream>

using namespace std;

int arr[100100];
int seg[400400];

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
int query(int l,int r, int x, int y,int I){
    if(y<l || r < x) return 0;
    if(x<=l && r<=y){
        return seg[I];
    }
    int m=l+r>>1;
    return query(l,m,x,y,I<<1)+query(m+1,r,x,y,I<<1|1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    build(1,n,1);
    cin >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        cout<<query(1,n,a,b,1)<<"\n";
    }
}