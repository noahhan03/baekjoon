#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

vector<pair<int,int>> adj[100010];
int disa[100010];
int disb[100010];
int disc[100010];
bool visa[100010];
bool visb[100010];
bool visc[100010];
int dis;
int n,m,a,b,c;
int L;
int num;

void dij(int st,int dis[],bool visit[]){
    fill(dis,dis+n+1,2e9);
    priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>> > pq;
    pq.emplace(0,st);
    dis[st]=0;
    while(!pq.empty()){
        int cur_node=pq.top().second;
        int cur_dis=pq.top().first;
        pq.pop();
        if(visit[cur_node])continue;
        visit[cur_node]=1;
        for(int i=0;i<adj[cur_node].size();i++){
            int nxt_node=adj[cur_node][i].first;
            int cost=adj[cur_node][i].second;
            if(cost+dis[cur_node]<dis[nxt_node] && !visit[nxt_node]){
                dis[nxt_node]=cost+dis[cur_node];
                pq.emplace(dis[nxt_node],nxt_node);
            }
        }
    }
}

int min(int a,int b)
{
    return a>b ? b : a;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    cin >> a >> b >> c;
    cin >> m;
    for(int i=0;i<m;i++){
        int d,e,l;
        cin >> d >> e >> l;
        adj[d].emplace_back(e,l);
        adj[e].emplace_back(d,l);
    }
    dij(a,disa,visa);
    dij(b,disb,visb);
    dij(c,disc,visc);
    for(int i=1;i<=n;i++){
        dis=min(min(disa[i],disb[i]), disc[i]);
        if(L<dis){
            L=dis;
            num=i;
        }
    }
    cout << num;
}