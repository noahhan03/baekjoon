#include<iostream>
#include<queue>
#include<vector>
#include<cstring>

using namespace std;

int dist[1005]; //st 에서 [i]까지 가는데 걸리는 거시기
vector<pair<int,int>> adj[1005];
int nn,EN;
bool vis[1005];

void dij(int start){
    dist[start]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push(make_pair(start,dist[start]));
    while(!pq.empty()){
        int cur_d=pq.top().second;
        int cur=pq.top().first;
        pq.pop();
        //if(vis[cur])continue;
        if(dist[cur]<cur_d)continue;
        //vis[cur]=1;
        for(int i=0;i<adj[cur].size();i++){
            int nxt=adj[cur][i].first;
            int nxt_dis=adj[cur][i].second+cur_d;
            if(nxt_dis<dist[nxt]){
                dist[nxt]=nxt_dis;
                pq.push(make_pair(nxt,nxt_dis));
            }
        }
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,M,st;
    cin >> N >> M;
    nn=N;
    for(int i=0;i<M;i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v,w));
    }
    cin >> st >> EN;
    memset(dist,98765432,sizeof(dist));
    dij(st);
    cout << dist[EN] ;
}
