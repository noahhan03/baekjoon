#include<iostream>

using namespace std;

int n,m;
int dist[110][110];

int main(){
    cin >> n >>m;
    
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        dist[a][b]=1;
        dist[b][a]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j && dist[i][j]!=1)dist[i][j]=10000000;
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
    int val=10000000;
    int output;
    for(int i=1;i<=n;i++){
        int temp=0;
        for(int j=1;j<=n;j++){
            temp+=dist[i][j];
        }
        if(temp<val){
            val=temp;
            output=i;
        }
    }
    cout << output;
}