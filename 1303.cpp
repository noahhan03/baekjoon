#include<iostream>
#include<string>
#include<queue>
#include<vector>

using namespace std;

int n,m;
int wb=0;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
char miro[110][110];
bool vis[110][110];

int bfs(int qq, int ww){
    queue<pair<int,int>> q;
    int cnt=1;
    q.emplace(qq,ww);
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int xx=x+dx[i];
            int yy=y+dy[i];
            if(xx<0 || xx>=n || yy<0 || yy>=m || vis[xx][yy])continue;
            if(miro[xx][yy]=='W' && wb && vis[xx][yy]==0){
                cnt++;
                q.emplace(xx,yy);
                vis[xx][yy]=1;
            }
            if(miro[xx][yy]=='B' && !wb && vis[xx][yy]==0){
                cnt++;
                q.emplace(xx,yy);
                vis[xx][yy]=1;
            }
        }
        vis[x][y]=1;
    }
    return cnt;
}


int main(){
    cin >> m >> n;
    int w=0,b=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){   
            cin >> miro[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j]){
                vis[i][j]=1;
                if(miro[i][j]=='W'){
                    wb=1;
                    int k=bfs(i,j);
                    // cout <<"w : "<<k<<"\n";
                    w+=k*k;
                }
                else{
                    wb=0;
                    int k=bfs(i,j);
                    // cout << "i,j : "<<i <<" " <<j <<"\n";
                    // cout <<"b : "<<k<<"\n";
                    b+=k*k;
                }
            }
        }
    }
    cout << w <<" "<<b;
}