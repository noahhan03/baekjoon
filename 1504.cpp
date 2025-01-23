#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int n,e;
int v1,v2; //꼭 거쳐야 하는 정점 2개 
vector<pair<int,int>> adj[810];
int dis[810];
bool vis[810];

int min(int a,int b)
{
    return a>b ? b : a;
}
void dij(int st)
{
    fill(dis,dis+n+1,2e9);
    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq;
    dis[st]=0;
    pq.emplace(dis[st],st);
    while(!pq.empty()){
        int cur_dis=pq.top().first;
        int cur_node=pq.top().second;
        pq.pop();
        if(vis[cur_node])continue;
        vis[cur_node]=1;
        for(int i=0;i<adj[cur_node].size();i++){
            int nxt_node=adj[cur_node][i].first;
            int cost=adj[cur_node][i].second;
            if(cost+dis[cur_node]<dis[nxt_node]){
                dis[nxt_node]=cost+dis[cur_node];
                pq.emplace(dis[nxt_node],nxt_node);
            }
        }
    }
}

void cls(){
    for(int i=0;i<805;i++){
        vis[i]=0;
    }
}

int main(){
    int chk=0;
    int g1,g2;
    cin >> n >> e;
    for(int i=0;i<e;i++){
        int a,b, w;
        cin >> a >> b >> w;
        adj[a].emplace_back(b,w);
        adj[b].emplace_back(a,w);
    }
    cin >> v1 >> v2;
    dij(1);
    int OneToV1=dis[v1];
    int OneToV2=dis[v2];
    if(dis[v1]==2e9 || dis[v2]==2e9){
        chk=1;
    }
    else {       
        cls();
        dij(v1);
        int V1ToV2=dis[v2];
        int V1ToN=dis[n];
        if(V1ToV2==2e9 || V1ToN==2e9)chk=1;
        else {
            cls();
            dij(v2);
            int V2ToV1=V1ToV2;
            int V2ToN=dis[n];
            g1=OneToV1+V1ToV2+V2ToN;
            g2=OneToV2+V2ToV1+V1ToN;
        }
    }
    if(chk)cout<<"-1";
    else cout << min(g1,g2);
}