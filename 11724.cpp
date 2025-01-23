#include<iostream>
#include<vector>

using namespace std;

vector<int> v[1010];
bool vis[1010];

void dfs(int st){
    if(vis[st]){
        return ;
    }
    vis[st]=1;
    for(int i=0;i<v[st].size();i++){
        dfs(v[st][i]);
    }
}

int main(){
    int n,m,cnt=0;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            cnt++;
            dfs(i);
        }
    }
    cout << cnt ;
}