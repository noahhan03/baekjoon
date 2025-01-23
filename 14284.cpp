#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n,m,s,t;
vector<pair<int,int>> adj[5010];
int dis[5010];
bool vis[5010];

void dij(){
    fill(dis,dis+n+1,1234567890);
    dis[s]=0;
    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq;
    pq.push({dis[s],s});
    while(!pq.empty()){
        int d=pq.top().first;
        int cur=pq.top().second;
        pq.pop();
        if(d>dis[cur])continue;
        if(vis[cur])continue;
        if(cur==t)break;
        vis[cur]=1;
        for(pair<int,int> i : adj[cur]){
            int nxt=i.first,cost=i.second;
            if(dis[nxt]>cost+dis[cur]){
                dis[nxt]=cost+dis[cur];
                pq.push({dis[nxt],nxt});
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    cin >> s >> t;
    dij();
    cout << dis[t];
}