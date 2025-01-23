#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

vector<int> v[32010];
int ddd[32010];
int n,m;

void bfs(){
    priority_queue<int, vector<int>,greater<int> > q;   
    for(int i=1;i<=n;i++){
        if(!ddd[i])q.push(i);
    }

    for(int i=0;i<n;i++){
        int node=q.top();
        cout << node <<" ";
        q.pop();
        for(int i=0;i<v[node].size();i++){
            int nxt=v[node][i];
            ddd[nxt]--; 
            if(!ddd[nxt])q.push(nxt); 
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        ddd[b]++;
    }
    bfs();
}