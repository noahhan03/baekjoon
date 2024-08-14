#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n,m;
char miro[1010][1010];
bool vis[1010][1010];
int cycle=0;

// U D L R 
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
vector<pair<int,int>> v[1010][1010];

// x i n 

void bfs(int xxx,int yyy){
    queue<pair<int,int>> q;
    q.push({xxx,yyy});
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();    
        if(vis[x][y])continue;
        vis[x][y]=true;
        // cout << " x : " << x << " y : "<< y <<" v[x][y].size : "<< v[x][y].size()<<"\n";
        for(int i=0;i<v[x][y].size();i++){
            int nx=v[x][y][i].first;
            int ny=v[x][y][i].second;
            // cout << " x : "<< x << " y: "<< y <<" nx "<< nx <<" ny : "<<ny<<"\n";
            if(vis[nx][ny])continue;
            else q.push({nx,ny});
        }
    }
    cycle++;
    return;
}

void sol(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j])continue;
            // cout << "i : "<< i<<" j : "<<j <<"\n";
            bfs(i,j);
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> miro[i][j];
            int idx=3;
            if(miro[i][j]=='U')idx=0;
            else if(miro[i][j]=='D')idx=1;
            else if(miro[i][j]=='L')idx=2;
            int cx=i+dx[idx];
            int cy=j+dy[idx];
            v[i][j].emplace_back(cx,cy);
            v[cx][cy].emplace_back(i,j);
        }
    }
    sol();
    cout << cycle;
}