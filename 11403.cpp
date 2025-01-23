#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
vector<int> v[110];
bool vis[110];

void dfs(int x){
    for(int i=0;i<v[x].size();i++){
        int cur=v[x][i];
        if(!vis[cur]){
            vis[cur]=1;
            dfs(cur);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int a;
            cin >> a;
            if(a)v[i].push_back(j);
        }
    }
    for(int i=0;i<n;i++){
        memset(vis,0,sizeof(vis));
        dfs(i);
        for(int j=0;j<n;j++){
            cout <<vis[j]<<" ";
        }
        cout <<"\n";
    }
}