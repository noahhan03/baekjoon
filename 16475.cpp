#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int n,m,k,l,p;
int switch_cnt;
int trap[10010];
int s,e;
vector<pair<int,int>> adj[10010];
int dis[10010];
bool vis[10010];

void dij()
{
    fill(dis,dis+n+1,2e9);
    // priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>> > pq;
    priority_queue<pair<pair<int,int> >, vector<pair<pair<int,int> >>, greater<pair<pair<int,int> >> > pq;
    dis[s]=0;
    pq.push(make_pair<pair<pair<int,int>>(dis[s],s,0)>);
    while(!pq.empty()){
        int cur_dis=pq.top().first;
        int cur_node=pq.top().second;
        pq.pop();
        if(vis[cur_node])continue;
        vis[cur_node]=1;
    }
}
int main(){
    cin >> n >> m >> k >> l >> p; 
    for(int i=0;i<k;i++){
        cin >> trap[i];
    }
    for(int i=0;i<m;i++){
        int a,b,w;
        adj[a].emplace_back(b,w);
    }
    cin >> s >> e; //s -> 시작, e -> 끝나는 지점 
}