#include<iostream>
#include<vector>
#include<queue>

using namespace std;

char miro[1010][1010];
int n,m;
bool vis[1010][1010][2];
int ans[1010][1010][2];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

void bfs(){
    queue<pair<pair<int,int>,int>> q;
    q.push(make_pair(make_pair(1,1),0));
    ans[1][1][0]=1;
    ans[1][1][1]=1;
    int x,y;
    vis[1][1][0]=1;
    while(!q.empty()){
        x=q.front().first.first;
        y=q.front().first.second;
        int d=q.front().second; //depth , 벽 부순 횟수
        q.pop();
        // cout <<"while at x : "<<x<<" y : "<< y <<" d : "<<d<<"\n";
        if(x==n && y==m )break;
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            int nd=d;
            // cout << "nx : "<<nx<<" ny : "<<ny<<" nd : "<<nd<<"\n";
            if(1>nx || nx>n || 1>ny || ny>m ) continue;
            if(nd==1 && miro[nx][ny]=='1')continue; 
            if(vis[nx][ny][nd])continue;
            if(miro[nx][ny]=='0'){
                vis[nx][ny][nd]=1;
                ans[nx][ny][nd]=ans[x][y][d]+1;
                q.push(make_pair(make_pair(nx,ny),nd));
            }
            if(miro[nx][ny]=='1' && !vis[nx][ny][1]){
                nd++;
                vis[nx][ny][nd]=1;
                ans[nx][ny][nd]=ans[x][y][d]+1;
                q.push(make_pair(make_pair(nx,ny),nd));
            }
            // cout << "ans["<<nx<<"]["<<ny<<"]["<<nd<<"] = "<<ans[nx][ny][nd]<<"\n";
        }
    }
    if(!(x==n && y==m)){    
        ans[n][m][0]=-1;
        ans[n][m][1]=-1;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> miro[i][j];
        }
    }
    bfs();
    // cout << "print ans \n";
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         cout << ans[i][j][0] <<" ";
    //     }
    //     cout <<endl;
    // }
    // cout <<"2nd\n";
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         cout << ans[i][j][1] <<" ";
    //     }
    //     cout <<endl;
    // }
    if(ans[n][m][0]==ans[n][m][1]){
        cout << ans[n][m][0];
    }
    else if(ans[n][m][0]<ans[n][m][1] && ans[n][m][0]!=0){
        cout << ans[n][m][0];
    }
    else if(ans[n][m][1]<ans[n][m][0] && ans[n][m][1]!=0){
        cout << ans[n][m][1];
    }
    else if(ans[n][m][0]==0 || ans[n][m][1]==0){
        cout << ans[n][m][0]+ans[n][m][1];
    }
}
