#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

bool a[100010];
long long dist[100010];
long long n,m;
bool vis[100010];
vector<pair<long long,long long>> adj[100010];

void dij(){
    fill(dist,dist+n+1, 9223372036854775806);
    dist[0]=0;
    priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>> > pq;
    pq.push({dist[0],0});
    while(!pq.empty()){
        long long  d=pq.top().first;
        long long cur=pq.top().second;
        pq.pop();
        if(d>dist[cur])continue;
        if(vis[cur] || a[cur] )continue;
        vis[cur]=1;
        for(pair<long long,long long> i : adj[cur]){
            long long nxt=i.first, cost=i.second;
            if(dist[nxt]>dist[cur]+cost)
            {
                dist[nxt]=dist[cur]+cost;
                pq.push({dist[nxt],nxt});
            }
        }
    }
}

int main(){
    cin>> n >>m;
    for(long long i=0;i<n;i++){
        cin >> a[i];
    }
    a[n-1]=0;
    for(long long i=0;i<m;i++){
        long long u,v,w;
        cin >> v >> u >> w;
        adj[v].push_back({u,w});
        adj[u].push_back({v,w});
    }
    dij();
    if(dist[n-1]==9223372036854775806)cout<<"-1";
    else cout << dist[n-1];
}