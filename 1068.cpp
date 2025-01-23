#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n;
int great_mother;
vector<int> v[53];
int bbbb[53];
bool vis[53];
int del;
int cnt;

void bfs(int d){
    queue<int> q;
    q.push(d);
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        if(vis[cur])continue;
        vis[cur]=1;
        if(v[cur].size()==0)cnt++;
        if(v[cur].size()==1){
            cout << "cur - "<<cur<<" "<<v[cur][0]<<"\n";
            if(v[cur][0]==del &&)cnt++; 
        }
        for(int i=0;i<v[cur].size();i++){
            int nxt=v[cur][i];
            if(!vis[nxt]){
                q.push(nxt);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){
        int t;
        cin >> t;
        if(t==-1){
            great_mother=i;
        }
        else {
            v[t].push_back(i);
        }
    }
    cin >> del;
    vis[del]=1;
    bfs(great_mother);
    cout << cnt;
}