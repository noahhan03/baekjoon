#include<iostream>

using namespace std;

int arr[100010];
int seg[400040];


void build(int l,int r,int I){
    ;
}

int main(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    int m;
    cin >> m;
    for(int i=0;i<m;i++){
        int x,y,k;
        cin >> x >> y >> k;
        cout << query(1,n,x,y,k,1);
    }
}