#include<iostream>
#include<queue>

using namespace std;


int N, M, map[110][80]; 
int dx[3]={-1,1,0};
int dy[3]={-1,1,0};
bool vis[110][80];
int cycle;
bool pot;

void bfs(int stx, int sty){
    int top=map[stx][sty];
    queue<pair<int,int>> q;
    q.push({stx,sty});
    vis[stx][sty]=true;

    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();

        // 인접 격자 확인 
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if((i+j)==4)continue;
                int nx=x+dx[i];
                int ny=y+dy[j];
                //범위 외 count x k
                if(nx<0 || nx >=N || ny<0 || ny>=M)continue;
                if(map[stx][sty]<map[nx][ny]){
                    pot=false;
                }
                if(vis[nx][ny] || map[stx][sty]!=map[nx][ny])continue;
                q.push({nx,ny});
                vis[nx][ny]=true;
            }
        }
    }
    
    
}



int main(){
    cin >> N >> M ;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> map[i][j];
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(vis[i][j])continue;
            if(!map[i][j])continue;
            pot=true;
            bfs(i,j);
            if(pot){
                cycle++;
            }
            
        }
    }
    cout << cycle;
}