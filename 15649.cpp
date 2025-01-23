#include<iostream>

using namespace std;

int ch[10], a[10], n, m;

void f(int x, int y){ // x개의 숫자를 결정했고, y까지 살펴봄
    if(x==m) {
        for(int i=0;i<m;i++) cout << a[i]<<" ";
        cout <<"\n";
        return;
    } 
    for(int i=1;i<=n;i++) if(!ch[i]){
        ch[i]=1; a[x]=i; f(x+1, i); ch[i]=0;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m; 
    f(0, 0);
}