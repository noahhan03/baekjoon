#include<iostream>

#define INF 2e9

using namespace std;



int n,m;
int adj[110][110];
int dist[110][110];

int mmiinn(int a, int b){
    if(a<b )return a;
    else return b;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m; //n 도시 개수 (정점), m 버스 개수 (간선)
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        if(adj[a][b])adj[a][b]=mmiinn(adj[a][b],c);
        else adj[a][b]=c;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)dist[i][j]=0;
            else if(adj[i][j])dist[i][j]=adj[i][j];
            else dist[i][j]=INF;
        }
    }
    for(int k = 1; k<= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j<=n; j++){
                if(dist[i][k]==INF || dist[k][j]==INF)continue;
                else dist[i][j] = mmiinn(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(dist[i][j]==INF)cout<<"0 ";
            else cout << dist[i][j] <<" ";  
        }
        cout <<"\n";
    }
}