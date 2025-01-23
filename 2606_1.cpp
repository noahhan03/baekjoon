#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> v[110];
bool vis[110];
int cnt=0;

void bfs(int st){
    queue<int> q;
    q.push(st);
    while(!q.empty()){
        int cur_node=q.front();
        vis[cur_node]=true;
        q.pop();
        for(int i=0;i<v[cur_node].size();i++){
            int nxt_node=v[cur_node][i]; // 2, 5 v[1][0]=2, v[1][1]=5;
            if(!vis[nxt_node]){
                q.push(nxt_node);
                cnt++;
                vis[nxt_node]=1;
            }
        }
    }
}

int main(){
    int n,s;
    cin >> n >> s;
    for(int i=0;i<s;i++){
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    bfs(1);
    cout << cnt ;
}