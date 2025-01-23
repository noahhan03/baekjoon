#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

int n,m,k;
int s[1010][1010];
bool vis[1010][1010];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};


bool bfs(int d){
    memset(vis,false,sizeof(vis));
    queue<pair<int,int>> q;
    int sum=0;
    for(int i=0;i<n;i++){
        if(i==0){
            for(int j=0;j<m;j++){
                if(s[i][j]<=d){
                    vis[i][j]=1;
                    q.emplace(i,j);
                    sum++;
                }
            }
        }
        else {
            if(!vis[i][0] && s[i][0]<=d){
                vis[i][0]=1;
                q.emplace(i,0);
                sum++;
            }
            if(!vis[i][m-1] && s[i][m-1]<=d){
                vis[i][m-1]=1;
                q.emplace(i,m-1);
                sum++;
            }
        }
    }
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0 || nx>=n || ny<0 || ny>=m)continue;
            if(vis[nx][ny]|| s[nx][ny]>d)continue;
            vis[nx][ny]=1;
            q.emplace(nx,ny);
            sum++;
        }
    }
    return (sum>=k);
}

int BinSear(){
    int low=1;
    int high=1e6;
    int mid,ans=-1;
    while(low<=high){
        mid=(low+high)/2;
        if(bfs(mid)){
            high=mid-1;
            ans=mid;
        }
        else {
            low=mid+1;
        }
    }
    return ans;
}

int main(){
    int min=2e9;
    cin >> n >> m >> k; //k 목표값 
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> s[i][j];
        }
    }
    cout << BinSear();
}