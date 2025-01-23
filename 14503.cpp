#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n,m,box[55][55];
bool vis[55][55];
bool clean[55][55]; //0 - 아직 청소x, 1 - 청소 한거 
int dy[4]={0,1,0,-1};
int dx[4]={-1,0,1,0};

int bfs(int ii,int jj,int d){
    int CntOfClean=0;
    queue<pair<int,int>> q;
    q.emplace(ii,jj);
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        int chk=0;
        q.pop();
        if(!clean[x][y]){
            clean[x][y]=1;
            CntOfClean++;
        }
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(box[nx][ny]==0 && clean[nx][ny]==0)chk=1;
        }
        // cout <<"last while : "<<"x : "<<x <<" y : "<<y<<"d :"<<d<<"\n";
        if(chk){
            // cout <<"last while1 : "<<"x : "<<x <<" y : "<<y<<"d :"<<d<<"\n";
            for(int i=0;i<4;i++){
                d--;
                if(d<0)d=3;
                int nx=x+dx[d];
                int ny=y+dy[d];
                if(clean[nx][ny]==0 && box[nx][ny]==0){
                    // cout << "nx : "<<nx <<" ny : "<<ny<<"d :"<<d<<"\n";
                    q.emplace(nx,ny);
                    break;
                }
            }
        }
        else {
            int nd=(d+2)%4;
            // cout << "d : "<<d<<"\n";
            // cout << "x : "<<x <<" y : "<<y<<"\n";
            int nx=x+dx[nd];
            int ny=y+dy[nd];
            if(box[nx][ny]==0)q.emplace(nx,ny);
            else {
                // cout << "nx : "<<nx <<" ny : "<<ny<<"\n";
                return CntOfClean;
            }
        }
    }
    // cout << "end of while\n";
    return CntOfClean;
}

int main(){
    cin >> n >> m;
    int stx,sty,std;
    cin >> stx >> sty >> std;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> box[i][j];
        }
    }
    cout << bfs(stx,sty,std);
}