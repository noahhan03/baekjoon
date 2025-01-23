#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> v[52];
bool vis[52][52];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

void bfs(int x,int y,int m,int n){
    queue<pair<int,int>> q;
    q.emplace(x,y);
    while(!q.empty()){
        int cur_x=q.front().first;
        int cur_y = q.front().second;
        q.pop();
        if(vis[cur_x][cur_y]==1){
            vis[cur_x][cur_y]=0;
            for(int i=0;i<4;i++){
                for(int j=0;j<4;j++){
                    int nxt_x=cur_x+dx[i];
                    int nxt_y=cur_y+dy[i];
                    if(nxt_x<0 || nxt_x>=m || nxt_y<0 || nxt_y>=n || vis[nxt_x][nxt_y]==0)continue;
                    q.emplace(nxt_x,nxt_y); 

                }
            }
        }
    }
}

int test(int m,int n, int k){
    int cnt=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            vis[i][j]=0;
        }
    }
    for(int i=0;i<k;i++){
        int a,b;
        cin >> a >> b; //a,b 에 배추가 심어져 있다. 
        vis[a][b]=1;
    }
    //cout << "asdf"<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(vis[i][j]==1){
                //cout << "start bfs : "<<i <<" , "<<j<<endl;
                bfs(i,j,m,n);
                cnt++;
            }  
        }
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; //T - test 케이스 개수 
    int m,n, k; //m 가로 , n 세로 , k 배추 심어져 있는 위치 
    cin >> t;
    for(int i=0;i<t;i++){
        cin >> m >> n >> k;
        cout << test(m,n,k)<<endl;
    }
    return 0;
}