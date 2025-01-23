#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> g[110];
bool vis[110];

int bfs(int st){
    int cnt=0;
    queue<int> q;
    q.push(st);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        vis[node]=1;
        cnt ++ ;
        for(int i=0;i<g[node].size();i++){
            int nxt=g[node][i];
            if(!vis[nxt]){
                q.push(nxt);
                vis[nxt]=1;
            }
        }
    }
    return cnt;
}

int main(){
    int n,m;
    cin >> n >> m; // n 정점 수, m 간선수
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    cout << bfs(1)-1 ;
}