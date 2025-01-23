#include<iostream>
#include<queue>
using namespace std;

bool vis[200010];
int direct[200010][2];
int indegree[200010];

void topological_sort(int n){
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(!indegree[i])q.emplace(i);
    }
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        if(vis[cur])continue;
        vis[cur]=true;
        int cur_a=direct[cur][0];
        int cur_b=direct[cur][1];
    }
}

int main(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        int a,b;
        cin >> a >> b;
        direct[i][0]=a;
        direct[i][1]=b;
        indegree[a]++;
        indegree[b]++;
    }
    topological_sort(int n);
}