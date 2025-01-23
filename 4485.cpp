#include<iostream>
#include<queue>
#include<stack>

using namespace std;

int map[130][130]; // map 
bool vis[130][130]; // 방문 확인
int cost[130][130]; //st cost[i][j] , 최소 비용 저장 
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int solve(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            vis[i][j]=0;
        }
    }
    for(int i=0;i<20001;i++)cost[i]=2147483646;
    dfs(n);
}
void dfs(int n){
    cost[0][0]=map[0][0];
    priority_queue<pair<int,pair<int,int>>> pq;
    pq.push(cost[0][0],(0,0));
    while(!pq.empty()){
        int cur_x=pq.top().second.first;
        int cur_y=pq.top().second.second;
        int cur_cost=pq.top().first;
        pq.pop();
        if(vis[cur_x][cur_y])continue;
        if(cur_cost>cost[cur_x][cur_y])continue;
        vis[cur_x][cur_y]=1;
        for(int i=0;i<4;i++){
            int nx=dx[i]+cur_x;
            int ny=dy[i]+cur_y;
            if(nx<0 || nx>=n || ny<0 || ny>=n )continue;
            if(vis[nx][ny])continue;
            int nxt_cost=cost
        }
    }
}

int main(){
    int n=1;int cnt=1;
    while(n){
        cin >> n;
        for(int i=0;i<n;i++){
            for(int j=0;j<n; j++){
                cin >> map[i][j];
            }
        }
        cout << "Problem "<<cnt<<": "<<solve(n)<<"\n";
    }
}