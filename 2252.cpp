#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> v[32010];
int degree[32010];
int n,m;

void bfs(){
    queue<int> q;   
    for(int i=1;i<=n;i++){
        if(!degree[i])q.push(i);
    }

    for(int i=0;i<n;i++){
        int node=q.front();
        cout << node <<" ";
        q.pop();
        for(int i=0;i<v[node].size();i++){
            int nxt=v[node][i];
            degree[nxt]--;
            if(!degree[nxt])q.push(nxt);
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        degree[b]++;
    }
    bfs();
}