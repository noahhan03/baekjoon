#include<iostream>
#include<vector>
#include<queue>
#define INF 2147483646

using namespace std;

vector<int> v[1010];
int D[1010];
int indegree[1010];
bool vis[1010];
int result[1010];

void reset(int n){
    for(int i=0;i<=n;i++){
        D[i]=0;
        vis[i]=false;
        indegree[i]=0;
        result[i]=0;
        v[i].clear();
    }
}

void solve(int n, int k){
    for(int i=1;i<=n;i++){
        cin >> D[i];
    }
    for(int i=0;i<k;i++){
        int x,y;
        cin >> x >> y;
        v[x].push_back(y);
        indegree[y]++;
    }
    int w;
    cin >> w;
    
    queue<int> q;

    for(int i=1;i<=n;i++){
        if(!indegree[i]){
            q.push(i);
            result[i]=D[i];
        }
    }
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        // if(vis[cur])continue;
        // vis[cur]=true;
        for(int i=0;i<v[cur].size();i++){
            int nxt=v[cur][i];
            indegree[nxt]--;
            result[nxt] = max(result[nxt], result[cur] + D[nxt]);
            if(!indegree[nxt])q.push(nxt);
        }
    }
    cout << result[w]<<"\n";
}
int main(){
    int T; 
    cin >> T;
    for(int i=0;i<T;i++){
        int n,k;
        cin >> n >> k;
        reset(n);
        solve(n,k);
    }
}