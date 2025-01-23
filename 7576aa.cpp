#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int box[1010][1010];
bool vis[1010][1010];
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
int output;
int m,n;
queue<pair<int,pair<int,int>>> q;
void bfs(){
    int calcdate=0;
    while(!q.empty()){
        int cur_x=q.front().first;
        int cur_y=q.front().second.first;
        calcdate=q.front().second.second;
        q.pop();
        for(int i=0;i<4;i++){
            int nxt_x=cur_x+dx[i];
            int nxt_y=cur_y+dy[i];
            if(nxt_x>=0 && nxt_x<n && nxt_y>=0 && nxt_y<m && vis[nxt_x][nxt_y]==0 && box[nxt_x][nxt_y]==0){
                vis[nxt_x][nxt_y]=1;
                box[nxt_x][nxt_y]=1;
                q.push(make_pair(nxt_x,make_pair(nxt_y,calcdate+1)));
            }
        }
        
    }
    output=calcdate;
}

int main(){
    cin >> m >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> box[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(box[i][j]==1 && vis[i][j]==0){
                vis[i][j]=1;
                q.push(make_pair(i,make_pair(j,0)));
            }
        }
    }
    bfs();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(box[i][j]==0){
                output=-1;
            }
        }
    }
    cout << output;
}