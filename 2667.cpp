#include<iostream>
#include<queue>
#include<stack>
using namespace std;

char arr[30][30];
bool vis[30][30];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};

int res[626];


int bfs(int x,int y){
    int cnt=0;
    queue< pair<int,int> > q;
    q.emplace(x,y);
    while(!q.empty()){
        int cx=q.front().first; 
        int cy=q.front().second;
        q.pop();
        if(vis[cx][cy])continue;
        vis[cx][cy]=1;
        for(int i=0;i<4;i++){
            int nx=cx+dx[i];
            int ny=cy+dy[i];
            if(arr[nx][ny]=='1' && vis[nx][ny]!=1){
                arr[nx][ny]='0';
                cnt++;
                q.emplace(nx,ny);
            }
        }
    }
    return cnt+1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,tot=0;
    priority_queue<int, vector<int>, greater<int>> pq;
    cin>> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]=='1'){
                int k=bfs(i,j);
                pq.push(k);
                tot++;
                // res[k]=1;
            }
        }
    }
    // for(int i=0;i<625;i++){
    //     if(res[i]==1){
    //         cout << i<<"\n";
    //     }
    // }
    cout << tot<<"\n";
    while (!pq.empty())
    {
        cout << pq.top()<<"\n";
        pq.pop();
    }
    
    // for(int i=0;i<pq.size();i++){
    //     cout << pq.top()<<"\n";
    //     pq.pop();
    // }
}