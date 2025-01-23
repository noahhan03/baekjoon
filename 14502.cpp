#include<iostream>
#include<queue>

using namespace std;

bool vis[10][10];
int map[10][10];
int mm[10][10];
int n,m;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};
queue<pair<int,int>> q;

void bfs(){
    while(!q.empty()){
        int cur_x=q.front().first;
        int cur_y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx=cur_x+dx[i];
            int ny=cur_y+dy[i];
            if(nx>=0 && nx<n && ny>=0 && ny<m && vis[nx][ny]==0 && map[nx][ny]==0){
                vis[nx][ny]=1;
                map[nx][ny]=2;
                q.emplace(nx,ny);
            }
        }
    }

}

int test(){
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(map[i][j]==0)cnt++;
        }
    }
    return cnt;
}

void cls(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            map[i][j]=mm[i][j];
            vis[i][j]=0;
            if(map[i][j]==2){
                q.emplace(i,j);
                vis[i][j]=1;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int output=0;
    int bigi,bigj,bigii,bigjj,bigiii,bigjjj;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> map[i][j];
            mm[i][j]=map[i][j];
            if(map[i][j]==2){
                q.emplace(i,j);
                vis[i][j]=1;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int ii=0;ii<n;ii++){
                for(int jj=0;jj<m;jj++){
                    for(int iii=0;iii<n;iii++){
                        for(int jjj=0;jjj<m;jjj++){
                            if((i==ii && j==jj) || (ii==iii && jj==jjj) || (i==iii && j==jjj)||mm[i][j]!=0 ||mm[ii][jj]!=0||mm[iii][jjj]!=0){
                                ; //겹치는게 하나라도 있는 상황
                            }
                            else {
                                map[i][j]=1;
                                map[ii][jj]=1;
                                map[iii][jjj]=1;
                                bfs();
                                int k=test();
                                if(output<k){
                                    output=k;
                                    bigi=i;
                                    bigj=j;
                                    bigii=ii;
                                    bigjj=jj;
                                    bigiii=iii;
                                    bigjjj=jjj;
                                }
                                cls();
                            }
                        }
                    }
                }
            }
        }
    }
    cout << output;
    //cout << "i,j set : "<<bigi <<" "<<bigj<<" | "<<bigii <<" "<<bigjj<<" | "<<bigiii <<" "<<bigjjj<<" | "<<endl;
}