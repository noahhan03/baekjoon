#include<iostream>
#include<vector>
#include<queue>

using namespace std;

char miro[1010][1010];
int n,m,k;
bool vis[1010][1010][11];
int ans[1010][1010][11];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int bfs(){
    queue<pair<pair<int,int>,int>> q;
    q.push(make_pair(make_pair(1,1),0));
    int x,y;
    vis[1][1][0]=1;
    while(!q.empty()){
        x=q.front().first.first;
        y=q.front().first.second;
        int d=q.front().second; //depth , 벽 부순 횟수
        q.pop();
        if(x==n && y==m )return ans[x][y][d]+1;
        // cout <<"while at x : "<<x<<" y : "<< y <<" d : "<<d<<"\n";
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            // cout << "nx : "<<nx<<" ny : "<<ny<<" nd : "<<d<<"\n";
            if(1>nx || nx>n || 1>ny || ny>m ) continue;
            if(d>=k && miro[nx][ny]=='1')continue; 
            if(vis[nx][ny][d])continue;
            if(d>k)continue;
            if(miro[nx][ny]=='0'){
                vis[nx][ny][d]=1;
                ans[nx][ny][d]=ans[x][y][d]+1;
                q.push(make_pair(make_pair(nx,ny),d));
            }
            if(miro[nx][ny]=='1' && !vis[nx][ny][d+1] && (d+1)<=k){
                vis[nx][ny][d+1]=1;
                ans[nx][ny][d+1]=ans[x][y][d]+1;
                q.push(make_pair(make_pair(nx,ny),d+1));
            }
            // cout << "ans["<<nx<<"]["<<ny<<"]["<<d<<"] = "<<ans[nx][ny][d]<<"\n";
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> miro[i][j];
        }
    }
    cout << bfs();
    // cout << "print ans \n";
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         cout << ans[i][j][0] <<" ";
    //     }
    //     cout <<endl;
    // }
    // cout <<"1st\n";
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         cout << ans[i][j][1] <<" ";
    //     }
    //     cout <<endl;
    // }
    // cout <<"2nd\n";
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         cout << ans[i][j][2] <<" ";
    //     }
    //     cout <<endl;
    // }
    
}
