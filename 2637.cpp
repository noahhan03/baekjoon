#include<iostream>
#include<queue>

using namespace std;

int inputcost[101][101]; // cost[a][b] - a부품 1개만들때 b부품 개수 
int basic[101]; //기본 부품 번호 
int basic_num;
int result[101]; // 필요한 기본 부품 개수 
int cost[101][101]; // cost[i][j] , i부품 1개를 만드는데 필요한 j부품(기본) 개수 
int indegree[101];
bool direction[101][101]; // a -> b 방향 확인
bool vis[101];
bool bas[101];

void toplogicalsort(int n){
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(!indegree[i]){
            q.push(i);
            basic[basic_num++]=i;
            bas[i]=true;
        }
    }

    while(!q.empty()){
        int cur=q.front();
        // cout << "cur : "<<cur<<"\n";
        q.pop();
        if(vis[cur])continue;
        vis[cur]=true;
        for(int i=1;i<=n;i++){
            // cout << "cur : "<<cur<<" i : "<<i<<"\n";
            if(direction[cur][i] ){
                indegree[i]--;
                if(bas[cur]){
                    cost[i][cur]+=inputcost[i][cur];
                }
                else {
                    for(int j=0;j<basic_num;j++){
                        cost[i][basic[j]]+=inputcost[i][cur]*cost[cur][basic[j]];
                    }
                }
            }
            if(!indegree[i])q.push(i);
        }
    }
}

int main(){
    int n,m; 
    // n 완제품 번호 
    cin >> n >> m;
    for(int i=0;i<(n+3);i++){
        for(int j=0;j<(n+3);j++)direction[i][j]=false;
    }
    for(int i=0;i<m;i++){
        int x,y,k;
        cin >> x >> y >> k;
        inputcost[x][y]=k;
        indegree[x]++;
        direction[y][x]=true;
    }
    toplogicalsort(n);
    for(int i=0;i<basic_num;i++){
        cout << basic[i]<<" "<< cost[n][basic[i]]<<"\n";
    }
}