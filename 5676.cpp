#include<iostream>

typedef long long ll;

using namespace std;

int seg[400040];
int a[100010];
int flag=1;


void mer(int I){
    seg[I]=seg[I<<1]*seg[I<<1|1];
}

void build(int l,int r,int I){
    if(l==r){
        seg[I]=a[l];
        return ;
    }
    int m=l+r >>1;
    build(l,m,I<<1);
    build(m+1,r,I<<1|1);
    mer(I);
}

int query(int l,int r,int x, int y,int I){
    if(y<l || r<x) return 1;
    if(x<=l && y>=r){
        if(seg[I]==0)flag=0;
        return seg[I];
    }
    if(flag){
        int m=l+r>>1;
        return query(l,m,x,y,I<<1)*query(m+1,r,x,y,I<<1|1);
    }
    else return 0;
}
void update(int l,int r,int x, int y,int I,int d){
    if(y<l || r<x) return ;
    if(x<=l && y>=r){
        if(d>0)seg[I]=1;
        else if(d==0){
            flag=0;
            seg[I]=0;
        }
        else seg[I]=-1;
        return ;
    }
    int m=l+r>>1;
    update(l,m,x,y,I<<1,d);update(m+1,r,x,y,I<<1|1,d);
    mer(I);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    auto &is = std::cin;
    bool first = true;
    int n, k;
    while(cin >> n >> k ){
        if(!first) std::cout << "\n";
        else first = false;
        
        for(int i=1;i<=n;i++){
            int temp;
            cin >> temp;
            if(temp>0)a[i]=1;
            else if(temp==0)a[i]=0;
            else a[i]=-1;
        }
        build(1,n,1);
        for(int i=0;i<k;i++){
            char cmd;
            int a,b;
            cin >> cmd;
            if(cmd=='C'){
                cin >> a>> b;
                if(b>0)b=1;
                else if(b==0)b=0;
                else b=-1;
                update(1,n,a,a,1,b);
            }
            if(cmd=='P'){
                cin >> a>> b;
                flag=1;
                if(query(1,n,a,b,1)>0)cout<<"+";
                else if(query(1,n,a,b,1)==0)cout<<"0";
                else cout<<"-";
            }
        }
    }
}