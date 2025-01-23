#include<iostream>
#include<stack>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;

int n;
bool map[11][11];
int delx[4]={-1,1,1,-1};
int dely[4]={-1,1,-1,1};
vector<pair<int,int>> bv;
vector<pair<int,int>> wv;
int bmax;
int wmax;


//vis 1이면 비숍 놓을 수 없는 곳 및 방문 완료

void dfs(int idx, bool vis[11][11],int cnt){
    if(idx==bv.size()){
        if(cnt>bmax){
            bmax=cnt;
        }
        return ;
    }
    
    int stx = bv[idx].first;
    int sty = bv[idx].second;
    // cout << "stx : "<<stx<<" sty : "<<sty<<"\n";
    if(!vis[stx][sty]){
        bool temp_vis[11][11];
        memcpy(temp_vis, vis, sizeof(bool)*11*11);  
        for(int i=0;i<4;i++){
            int x=stx+delx[i];
            int y=sty+dely[i];
            while(x>=0 && x<n &&y>=0 && y<n){
                temp_vis[x][y]=1;
                x+=delx[i];
                y+=dely[i];
            }
        }
        temp_vis[stx][sty]=true;
        dfs(idx + 1, temp_vis, cnt + 1);
        // dfs(idx -1, temp_vis, cnt + 1);
    }
    dfs(idx+1,vis,cnt);
    // dfs(idx-1,vis,cnt);
    
}
void wdfs(int idx, bool vis[11][11],int cnt){
    if(idx==wv.size()){
        if(cnt>wmax){
            wmax=cnt;
        }
        return ;
    }
    
    int stx = wv[idx].first;
    int sty = wv[idx].second;
    
    if(!vis[stx][sty]){
        bool temp_vis[11][11];
        memcpy(temp_vis, vis, sizeof(bool)*11*11);  
        for(int i=0;i<4;i++){
            int x=stx+delx[i];
            int y=sty+dely[i];
            while(x>=0 && x<n &&y>=0 && y<n){
                temp_vis[x][y]=1;
                x+=delx[i];
                y+=dely[i];
            }
        }
        temp_vis[stx][sty]=true;
        wdfs(idx + 1, temp_vis, cnt + 1);
        // dfs(idx -1, temp_vis, cnt + 1);
    }
    wdfs(idx+1,vis,cnt);
    // dfs(idx-1,vis,cnt);
    
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    bool bvis[11][11]={0,};
    bool wvis[11][11]={0,};
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> map[i][j];
            if(map[i][j] && (i+j)%2){
                bv.emplace_back(i,j);
                bvis[i][j]=!map[i][j];
            }
            else if(map[i][j] && (i+j)%2==0){
                wv.emplace_back(i,j);
                wvis[i][j]=!map[i][j];
            }
        }
    }
    dfs(0,bvis,0);
    wdfs(0,wvis,0);
    // cout << "b : "<<bmax<<"\nw : "<<wmax<<"\n"; 
    cout << bmax+wmax;
}