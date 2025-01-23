#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

vector<int> g[1010];
bool vis[1010]; //이미 방문했는지 
bool vis1[1010];
//dfs 시작하는 곳, 방문한데 
void DFS(int st){
    if(vis[st]){
        return ;
    }
    vis[st]=1; //방문했으니까~ 
    cout << st <<" "; // 문제에서 요규하는거 
    for(int i=0;i<g[st].size();i++){
        DFS(g[st][i]); //st와 연결된거 탐색
    }
}

void bfs(int st){
    queue<int> q;
    q.push(st);
    while(!q.empty()){
        int node = q.front(); // q에서 pop 할거 
        q.pop(); 
        vis1[node]=1;//방문함 .
        cout << node << " ";
        for(int i=0;i<g[node].size();i++){
            int nxt = g[node][i];
            if(!vis1[nxt]){
                q.push(nxt);
                vis1[nxt]=1; // 다시 넣는거 또다시 방지
            }
        }
    }
}

int main(){
    int n,m,v;
    cin >> n >> m >> v ; //정점의 개수 N(1 ≤ N ≤ 1,000), 간선의 개수 M(1 ≤ M ≤ 10,000), 탐색을 시작할 정점의 번호 V가
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;  
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        sort(g[i].begin(),g[i].end());
    }
    DFS(v);
    cout<<endl;
    bfs(v);
}