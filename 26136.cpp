#include<iostream>

using namespace std;

int ans;
int bill[6];

void solve(int cnt, int w, int v){
    if(w>15)return ;
    if((cnt<=3 && w<=10) || (cnt>=4 && w<=15)) {
        if(ans<v)ans=v;
    }
    for(int i=1;i<=5;i++){
        solve(cnt+1,w+i,v+bill[i]);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); 
    for(int i=1;i<=5;i++)cin >> bill[i];
    solve(0,0,0);
    cout << ans; 
}