#include<iostream>
#include<queue>

using namespace std;

bool chk[100100];
bool flag=false;
int count;
int pathcnt;

void bfs(int st,int k){
    queue<pair<int,int>> q;
    q.push(make_pair(st,0));
    while(!q.empty()){
        int x=q.front().first;
        int cnt=q.front().second;
        q.pop();
        chk[x]=1;
        if(flag && cnt>count)continue;
        if(x==k && !flag){
            flag=true;
            count=cnt;
            pathcnt++;
        }
        if(x==k && flag && cnt==count)pathcnt++;
        int nx=x-1;
        if(nx>=0 && !chk[nx])q.push(make_pair(nx,cnt+1));
        nx+=2;
        if(nx<=100000 && !chk[nx])q.push(make_pair(nx,cnt+1));
        nx=x*2;
        if(nx<100001 && !chk[nx])q.push(make_pair(nx,cnt+1));
    }
}

int main(){
    int n,k;
    cin >> n >> k;
    bfs(n,k);
    cout << count <<"\n"<<pathcnt-1;
    
}