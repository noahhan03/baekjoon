#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int v,e,k;
vector<pair<int,int>> adj[20010];
bool vis[20010];
int dis[20010]; // k에서 시작하서 [i] i번째 가는 최단 경로 , 돌리면서 계속 update

void dick(int st){
    fill(dis,dis+v+1,2e9); //1e9 == 10^9 
    priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>> > pq;
    dis[st]=0;
    pq.emplace(dis[st],st);
    while(!pq.empty()){
        int cur_dis=pq.top().first; //dis[st]
        int cur_node=pq.top().second; //st 
        pq.pop();
        vis[cur_node]=1;
        for(int i=0;i<adj[cur_node].size();i++){
            int nxt_node=adj[cur_node][i].first;
            int cost=adj[cur_node][i].second;
            if(!vis[nxt_node] && (cost+dis[cur_node])<dis[nxt_node] ){
                dis[nxt_node]=cost+dis[cur_node];
                pq.emplace(dis[nxt_node],nxt_node);
            }
        }
    }
}

int main(){
    cin >> v >> e >> k;
    for(int i=0;i<e;i++){
        int a,b,w;
        cin >> a >> b >> w;
        adj[a].emplace_back(b,w);
    }
    dick(k);
    for(int i=1;i<=v;i++){
        if(dis[i]==2e9)cout<<"INF\n";
        else cout <<dis[i]<<"\n";
    }
}
