#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int n;
int degree[510];
vector<int> v[510];

void bfs(){
    queue<int> q;
    for(int i=1;i<=n;i++){
        cout << "degre : "<<degree[i]<<endl;
        if(!degree[i])q.push(i);
    }
    for(int i=0;i<n;i++){
        int node=q.front();
        cout << node << "nn ";
        q.pop();
        int nxt=v[node][0];
        cout << nxt << endl;
        q.push(nxt);
    }
}

int main(){
    int T; // T testcase 개수 
    int m;
    cout <<"T : ";
    cin >> T;
    while(T--){
        cout <<"n : ";
        cin >> n;
        int a,b;
        cin >> a; 
        degree[a]=0;
        for(int i=1;i<n;i++){
            cin >> b;
            v[a].push_back(b);
            degree[b]++;
            a=b;
        }
        cout <<"m : ";
        cin >> m;
        int chk=0;
        for(int i=0;i<m;i++){
            int a,b;
            cin >> a >> b; 
            v[a].push_back(b);
            int t=degree[a];
            degree[a]=degree[b];
            degree[b]=t;
            if(v[b][0]==a)v[b][0]=-1;
        }
        cout << "data 입력은 끝"<<endl;
        if(chk){
            cout<<"IMPOSSIBLE"<<endl;
        }
        else bfs();
    }
}