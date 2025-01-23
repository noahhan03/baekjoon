#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int r,c;
bool UsedChar[30];
int maxx=0;
char miro[22][22];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

void bfs(int x, int y, bool p[],int cnt, bool vis[30][30]){
    // cout << "cur bfs : "<<"x : "<<x <<" y : "<<y <<"  : " << miro[x][y]<<"\n";
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        int idx=miro[nx][ny]-'A';
        if(vis[nx][ny]==true || nx<0 || ny<0 || nx>=r || ny>=c || p[idx]==true)continue;
        vis[nx][ny]=true;
        p[idx]=true;
        int tmp=cnt+1;
        bfs(nx,ny,p,tmp,vis);
        vis[nx][ny]=false;
        p[idx]=false;
    }
    if(maxx<cnt)maxx=cnt;
    return;
}

int main(){
    cin >> r >> c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++)cin >> miro[i][j];
    }
    int idx=miro[0][0]-'A';
    bool vis[30][30]={0,};
    vis[0][0]=true;
    UsedChar[idx]=true;
    bfs(0,0,UsedChar,1,vis);

    cout << maxx<<'\n';
}