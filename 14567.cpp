#include<iostream>
#include<queue>
#include<utility>
using namespace std;

int n,m;
bool direct[1010][1010];
bool vis[1010];
int output[1010];
int indegree[1010]; // 학기 측정 

void topological_sort(){
    queue<pair<int,int>> q;
    for(int i=1;i<=n;i++){
        if(!indegree[i]){
            q.emplace(i,1);
            output[i]=1;
        }
    }
    while(!q.empty()){
        int cur=q.front().first;
        int cur_sem=q.front().second;
        q.pop();
        if(vis[cur])continue;
        vis[cur]=1;
        for(int i=1;i<=n;i++){
            if(direct[cur][i]){
                indegree[i]--;
                if(!indegree[i] && !vis[i]){
                    q.emplace(i,cur_sem+1);
                    output[i]=cur_sem+1;
                }
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b; 
        cin >> a >> b;
        direct[a][b]=true;
        indegree[b]++;
    }
    topological_sort();
    for(int i=1;i<=n;i++){
        cout << output[i]<<" ";
    }
}