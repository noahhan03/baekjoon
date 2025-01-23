#include<iostream>

using namespace std;

int n,m;
bool vis[10];
int a[10];

void f(int x, int y) 
{
    if(x==m){
        for(int i=0;i<m;i++) cout << a[i]<<" ";
        cout <<"\n";
        return;
    }
    for(int i=1;i<=n;i++){
        a[x]=i;f(x+1,i);
    }
}

int main(){
    cin >> n >> m;
    f(0,0);
}