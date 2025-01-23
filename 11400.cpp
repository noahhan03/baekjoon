#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> node[100001];
bool vis[100001];
int id,nodeId[100001];
bool finished[100001];
vector<vector<int>> SCC;
stack<int> s;



int tarjan(int n){
    nodeId[n]=++id;
    s.push(n);

    int parent=nodeId[n];

    for(int i=0;i<node[n].size();i++){
        int y=node[n][i];
        if(y==parent)continue;
        if(!nodeId[y])parent=min(parent,tarjan(y));
        else if(!finished[y])parent=min(parent,nodeId[y]);
    }

    if(parent==nodeId[n]){
        vector<int> scc;
        while(1){
            int t= s.top();
            s.pop();
            scc.push_back(t);
            finished[t]=true;
            if(t==n)break;  
        }
        for(int i=0;i<scc.size();i++){
            cout << n <<"으로 tarjan , scc "<<i<<"번째 = "<<scc[i]<<"\n";
        }
        SCC.push_back(scc);
    }
    return parent;
}

int main(){
    // 입력
    int v,e; //이는 그래프가 V개의 정점과 E개의 간선으로 이루어져 있다는 의미
    cin >> v >> e;
    for(int i=0;i<e;i++){

        //두 정수 A, B가 주어진다. 이는 A번 정점과 B번 정점이 연결되어 있다는 의미이며, 방향은 양방향이다. 
        int a,b;
        cin >> a >> b;
        node[a].push_back(b);
        node[b].push_back(a);
    }
     for (int i = 1; i <=v; i++)
        if (!nodeId[i])
            cout << i<<" : "<<tarjan(i)<<"\n";
    

    // 출력 
    // 단절선 개수 k 
    //둘째 줄부터 K개 줄에는 단절선을 사전순으로 한 줄에 하나씩 출력한다. 
    //간선은 "A B" 형식으로 출력해야 하고, A < B를 만족해야 한다. 
    //같은 간선은 한 번만 출력하면 된다. 즉, "A B"를 출력한 경우에 "B A"는 출력할 필요가 없다.
}