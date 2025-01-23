#include<iostream>

using namespace std;

int arr[100010];
pair<int,int> seg[400040];
int mmm;
int dex;

void mer(int I){
    if(seg[I<<1].first <= seg[I<<1|1].first){
        seg[I].first=seg[I<<1].first; // 작은값 
        seg[I].second=seg[I<<1].second; //index 값 
    }
    else {
        seg[I].first=seg[I<<1|1].first;
        seg[I].second=seg[I<<1|1].second; 
    }

}

void build(int l,int r,int I){
    if(l==r){
        seg[I].first=arr[l];
        seg[I].second=l;
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
        if(mmm>seg[I].first){
            mmm=seg[I].first;
            dex=seg[I].second;
        }
        if(mmm==seg[I].first && dex>seg[I].second){
            dex=seg[I].second;
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
        seg[I].first=d;
        seg[I].second=l;
        return ;
    }
    int m=l+r>>1;
    update(l,m,x,y,I<<1,d);
    update(m+1,r,x,y,I<<1|1,d);
    mer(I);
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    build(1,n,1);
    int m;
    cin >> m; 
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        if(a==1){
            update(1,n,b,b,1,c);
        }
        else {
            dex=0;
            mmm=2e9;
            query(1,n,b,c,1);
            cout << mmm <<"\n";
        }
    }
}