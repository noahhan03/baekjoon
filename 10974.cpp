#include<iostream>

using namespace std;

int n;
int p[8];
bool chk[8];
void f(int index)
{
    if(index==n){
        for(int i=0;i<n;i++){
            cout<<p[i]<<' ';
        }
        cout << "\n";
        return ;
    }
    for(int x=1;x<=n;x++)
    {
        if(chk[x])continue;
        chk[x]=1;
        p[index]=x;
        f(index+1);
        chk[x]=0;
        p[index]=0;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    f(0);
}