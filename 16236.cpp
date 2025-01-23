#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n,shark_size=2,dx[4]={1,0,-1,0},dy[4]={0,-1,0,1},stx,sty;
int map[21][21];
int fish_cnt,tt;
bool vis[21][21];

void bfs(){
    queue<pair<int,int>> q;
    q.emplace(stx,sty);
    while(!q.empty()){
        int curx=q.front().first;
        int cury=q.front().second;
        q.pop();
        if(vis[curx][cury])continue;
        vis[curx][cury]=1;
        int cur_fish=0;
        for(int i=0;i<4;i++){
            int nx=curx+dx[i];
            int ny=cury+dy[i];
            if(nx<0 || nx>=n || ny<0 || ny>=n || vis[nx][ny] || shark_size<=map[nx][ny])continue;
            move_p=1;
            if(map[nx][ny])
        }
    }
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int temp;
            cin >> temp;
            map[i][j]=temp; 
            if(temp==9){
                stx=i;sty=j;
                map[i][j]=0;
            }
            else if(!temp)fish_cnt++;
        }
    }
    if(fish_cnt){
        bfs();
        cout << tt;
    }
    else cout <<"0";
}