#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<pair<int,int>> v[1010];
bool vis[1010];


void cls(){
    for(int i=0;i<1005;i++)vis[i]=0;
}
int bfs(int cur, int en){
    queue<pair<int,int>> q;
    // int dis=0;
    q.emplace(cur,0);
    while(!q.empty()){
        int node=q.front().first;
        int dis=q.front().second;
        if(node==en)return dis;
        q.pop();
        vis[node]=1;
        for(int i=0;i<v[node].size();i++){
            int nxt=v[node][i].first;
            int nxt_dis=v[node][i].second;
            if(!vis[nxt])q.emplace(nxt,nxt_dis+dis);
        }
    }
    return -1;
}

int main(){
    int n,m;
    cin >> n >> m;//n노드개수 , m노드 쌍의 개수? 
    for(int i=0;i<(n-1);i++){
        int a,b,len; 
        cin >> a >> b >> len;
        v[a].push_back(pair<int,int>(b,len));
        v[b].emplace_back(a,len);
    }
    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >> y;
        cout <<bfs(x,y) << endl;
        cls();
    }
}