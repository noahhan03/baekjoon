#include<iostream>
#include<vector>
#include<queue>

using namespace std;

bool vis[510][510];
vector<pair<int,int>> map; // 그림이 있는 위치, 그러니까 1이 있는 위치만 저장하는거고 
int box[510][510];// bfs, dfs 돌릴거 
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int mmax=0;
int cnt=0;
int n,m;

void bfs(int ii,int jj){
    int output=0;
    queue<pair<int,int>> q;
    q.emplace(ii,jj);
    vis[ii][jj]=1;
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        output++;
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(0<=nx && nx<n && 0<=ny && ny<m && box[nx][ny] && !vis[nx][ny]){
                q.emplace(nx,ny);
                vis[nx][ny]=1;
            }
        }
    }
    if(mmax<output)mmax=output;
}
int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int tmp;
            cin >> tmp;
            if(tmp){
                map.emplace_back(i,j); 
                box[i][j]=1; 
            }
        }
    }
    for(int i=0;i<map.size();i++){
        int ii=map[i].first;
        int jj=map[i].second;
        cout << ii << ' ' << jj<<endl;
        if(!vis[ii][jj]){
            cnt ++;
            bfs(ii,jj);
            vis[ii][jj]=1;

        }
    }
    cout << cnt << endl;
    cout << mmax << endl;
}