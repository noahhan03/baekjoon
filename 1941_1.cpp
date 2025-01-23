#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

char miro[5][5];
int ans=0;
bool vis[5][5];
int dx[4]={0,0,1,-1};
int dy[5]={1,-1,0,0};

bool bfs(int idx, bool comb[25]){
    memset(vis, 0, sizeof(vis));
    int count=0;
    queue<pair<int,int>> q;
    int xx=idx/5;
    int yy=idx%5;
    q.emplace(xx,yy);
    vis[xx][yy]=true;
    while (!q.empty())
    {
        int x=q.front().first;
        int y=q.front().second;
        count++;
        if(count==7)return true;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= 5 || nx >= 5) continue;
            if (!comb[nx * 5 + ny]) continue;
            if (vis[nx][ny]) continue;

            q.push({ nx,ny });
            vis[nx][ny] = true;
        }
    }
    return false;
    
}

void dfs(int s, int cnt, int idx, bool comb[25]){
    if(cnt==7){
        if(s>=4 && bfs(idx,comb))ans++;
        return;
    }
    for(int i=idx;i<25;i++){
        if(comb[i])continue;
        comb[i]=true;
        int x=i/5;
        int y=i%5;
        dfs(s+(miro[x][y] == 'S') , cnt+1, i, comb);
        comb[i]=false;
    }
}

int main(){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin >> miro[i][j];
        }
    }
    bool comb[25]={0,};
    dfs(0,0,0,comb);
    cout << ans;
}