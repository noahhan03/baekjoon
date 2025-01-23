#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

// n명의 학생 x번에서 모여 파티 ~ m개의 도로 w가 시간 소요 

int n,m,x; 
vector<pair<int,int>> adj[10010];
int min_time_go[1010]; // 걸리는 최단 시간 가는데- 계속 update
int min_time_back[1010];//돌아오는데 최단 
int min_time_tot[1010]; //go+back 최단 
int time_tot;
bool vis_g[1010];
bool vis_b[1010];

void dij_g(int st){
    for(int i=0;i<=n;i++)vis_g[i]=0;
    fill(min_time_go,min_time_go+n+1,2e9);
    priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>> > pq;
    min_time_go[st]=0;
    pq.emplace(min_time_go[st],st);
    while(!pq.empty()){
        int cur_dis=pq.top().first;
        int cur_node=pq.top().second;
        pq.pop();
        if(cur_node==x)break;
        vis_g[cur_node]=1;
        for(int i=0;i<adj[cur_node].size();i++){
            int nxt_node=adj[cur_node][i].first;
            int cost=adj[cur_node][i].second;
            if(vis_g[nxt_node])continue;
            if(min_time_go[nxt_node]>cost+min_time_go[cur_node]){
                min_time_go[nxt_node]=cost+min_time_go[cur_node];
                pq.emplace(min_time_go[nxt_node],nxt_node);
            }
        }
    }
}
void dij_b(int st,int en){
    for(int i=0;i<=n;i++)vis_b[i]=0;
    fill(min_time_back,min_time_back+n+1,2e9);
    priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>> > pq;
    min_time_back[st]=0;
    pq.emplace(min_time_back[st],st);
    while(!pq.empty()){
        int cur_dis=pq.top().first;
        int cur_node=pq.top().second;
        pq.pop();
        if(cur_node==en)break;
        vis_b[cur_node]=1;
        for(int i=0;i<adj[cur_node].size();i++){
            int nxt_node=adj[cur_node][i].first; 
            int cost=adj[cur_node][i].second;
            if(vis_b[nxt_node])continue;
            if(min_time_back[nxt_node]>cost+min_time_back[cur_node]){
                min_time_back[nxt_node]=cost+min_time_back[cur_node];
                pq.emplace(min_time_back[nxt_node],nxt_node);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> x;
    for(int i=0;i<m;i++){
        int a,b,w;
        cin >> a >> b >> w;
        adj[a].emplace_back(b,w);
    }
    int max=0;
    for(int i=1;i<=n;i++){
        dij_g(i);
        dij_b(x,i);
        time_tot=min_time_back[i]+min_time_go[x];
        // cout << "min : "<<time_tot<<endl;
        if(max<time_tot)max=time_tot;
    }
    cout << max;
}