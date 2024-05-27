#include<iostream>
#include<queue>
#include<stack>
#include<utility>
#define INF 2147483646

using namespace std;

vector<pair<int,int>> adj[50010];
bool vis[50010];
int dis[50010]; // st에서 i 까지 가는데 걸리는 최소 비용

void dij(int n,int m){
    int st=1;
    fill(dis,dis+n+2,INF);
    dis[st]=0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(dis[st],st));
    while (!pq.empty())
    {
        int cur_dist=pq.top().first;
        int cur=pq.top().second;
        pq.pop();
        if(vis[cur])continue;
        if(cur_dist>dis[cur])continue;
        vis[cur]=1;
        for(int i=0;i<adj[cur].size();i++){
            int nxt=adj[cur][i].first;
            int nxt_dis=adj[cur][i].second+cur_dist;
            if(nxt_dis<dis[nxt]){
                dis[nxt]=nxt_dis;
                pq.push(make_pair(nxt_dis, nxt));
            }
        }
    }
    
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    dij(n,m);
    cout << dis[n];
}