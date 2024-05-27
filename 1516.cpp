#include<iostream>
#include<vector>
#include<utility>
#include<queue>
using namespace std;

int cost[510];
bool vis[510]; 
vector<int> dd[510]; // dd[i]는 쏘는 애들
int indegree[510];
int cost_res[510];
int big(int a,int b){
    if(a>b)return a;
    return b;
}

void top_sort(int n){
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(!indegree[i]){
            q.push(i);
            cost_res[i]=cost[i];
        }
    }
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(int i=0;i<dd[cur].size();i++){
            int nxt=dd[cur][i];
            indegree[nxt]--;
            cost_res[nxt]=big(cost_res[nxt],cost[nxt]+cost_res[cur]);
            if(!indegree[nxt]){
                q.push(nxt);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> cost[i];
        while (1)
        {
            int t;
            cin >> t;
            if(t==-1)break;
            else {
                dd[t].push_back(i);
                indegree[i]++;
            }
        }
    }
    top_sort(n);
    for(int i=1;i<=n;i++){
        cout <<cost_res[i]<<"\n";
    }
}