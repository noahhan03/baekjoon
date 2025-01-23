#include<iostream>
#include<queue>
#include<vector>
#include<cstring>

using namespace std;

vector<int> tree[501];
vector<int> ee[501];
bool vis[510];
int m,n;
int cnt=0;

void dfs(vector<int> v[],int x){
    
    vis[x]=true;
    for(int i=0;i<v[x].size();i++){
        int cur=v[x][i];
        if(!vis[cur]){
            vis[cur]=true;
            cnt++;
            dfs(v,cur);
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        tree[a].push_back(b);
        ee[b].push_back(a);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        cnt=0;
        memset(vis, 0, sizeof(vis));
        dfs(tree, i);
        memset(vis, 0, sizeof(vis));
        dfs(ee, i);
        if(cnt==(n-1))ans++;
    }
    cout << ans;
}