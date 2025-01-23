#include<iostream>
#include<queue>

using namespace std;

bool chk[200100];

void bfs(int st,int k){
    queue<pair<int,int>> q;
    q.push(make_pair(st,0));
    chk[st]=1;
    while(!q.empty()){
        int x=q.front().first;
        int cnt=q.front().second;
        q.pop();
        if(x==k){
            cout<<cnt;
            break;
        }
        for(int i=0;i<3;i++){
            if(!i){
                int nx=2*x;
                
                if(!chk[nx] && nx<100001 && nx>=0){
                    q.push(make_pair(nx,cnt));
                    chk[nx]=1;
                }
            }
            else if(i==1){
                int nx=x+1;
                if(!chk[nx] && nx<100001 && nx>=0){
                    q.push(make_pair(nx,cnt+1));
                    chk[nx]=1;
                }
            }
            else {
                int nx=x-1;
                if(!chk[nx]&& nx<100001&& nx>=0){
                    q.push(make_pair(nx,cnt+1));
                    chk[nx]=1;
                }
            }
        }
    }
}

int main(){
    int n,k;
    cin >> n >> k;
    bfs(n,k);
    
}