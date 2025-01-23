#include<iostream>
#include<vector>
#include<queue>

using namespace std;

char miro[110][110];
bool vis[110][110];
bool vis1[110][110];
int n;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

void bfs1(int ii,int jj, char chk){
    queue<pair<int,int>> q;
    q.emplace(ii,jj);
    vis1[ii][jj]=1;
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(0>nx || nx>=n || ny<0 || n<=ny)continue;
            if(vis1[nx][ny])continue;
            if(miro[nx][ny]==chk && !vis1[nx][ny]){
                q.emplace(nx,ny);
                vis1[nx][ny]=1;
            }
            else if((chk=='G' || chk=='R') && (miro[nx][ny]=='G' || miro[nx][ny]=='R') && !vis1[nx][ny]){
                q.emplace(nx,ny);
                vis1[nx][ny]=1;
            }
        }
    }
}

void bfs(int ii,int jj, char chk){
    queue<pair<int,int>> q;
    q.emplace(ii,jj);
    vis[ii][jj]=1;
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(0>nx || nx>=n || ny<0 || n<=ny)continue;
            if(vis[nx][ny])continue;
            if(miro[nx][ny]==chk && !vis[nx][ny]){
                q.emplace(nx,ny);
                vis[nx][ny]=1;
            }
        }
    }
}

int main(){
    int cnt1=0,cnt2=0;
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> miro[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!vis[i][j]){
                bfs(i,j,miro[i][j]);
                cnt1++;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!vis1[i][j]){
                bfs1(i,j,miro[i][j]);
                cnt2++;
            }
        }
    }
    cout << cnt1 <<" "<<cnt2;
}