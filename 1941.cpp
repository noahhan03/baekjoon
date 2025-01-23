#include<iostream>
#include<vector>
#include<queue>
#include<array>
#include<math.h>
#include<cstring>
using namespace std;

char miro[5][5];
vector<pair<int,int> > v; // 이다솜파 위치
vector<array<array<bool, 5>, 5>> SumP;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

bool equal(const array<array<bool, 5>, 5>& vis, const array<array<bool, 5>, 5>& tmp){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(vis[i][j]!=tmp[i][j])return false;
        }
    }
    return true;
}

void back_track(int cnt, vector<pair<int,int>> cur, int cntS, int cntY, array<array<bool, 5>, 5>& vis,  int x,int y){
    if(cnt==7){
        
        int flag=1;
        for(auto& P : SumP){
            if(equal(vis,P) &&cntY<=3){
                flag=0;
                break;
            }
        }
        if(flag){
            
            SumP.push_back(vis);
        }
        return;
    }
    for(int j=0;j<cur.size();j++){
    for(int i=0;i<4;i++){
        int xx=cur[j].first;
        int yy=cur[j].second;
        int nx=xx+dx[i];
        int ny=yy+dy[i];
        // cout << "nx : "<<nx <<" ny : "<<ny<<"\n";
        // for(int i=0;i<5;i++){
        //     for(int j=0;j<5;j++){
        //         cout << vis[i][j]<<" ";
        //     }
        //     cout <<"\n";
        // }
        if(nx<0 || nx>4 || ny<0 || ny>4 || vis[nx][ny])continue;
        vis[nx][ny]=true;
        if(cntY>2 && miro[nx][ny]=='Y'){
            vis[nx][ny]=false;
            continue;
        }
        int newS=cntS,newY=cntY;
        if(miro[nx][ny]=='Y')newY++;
        else newS++;
        cur.emplace_back(nx,ny);
        back_track(cnt+1, cur, newS,newY,vis,nx,ny );
        cur.erase(cur.begin() + cur.size());
        vis[nx][ny]=false;
    }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin >> miro[i][j];
            if(miro[i][j]=='S'){
                v.emplace_back(i,j);
            }
        }
    }
    
    array<array<bool, 5>, 5> vis = {false};
    for(int i=0;i<v.size();i++){
        vector<pair<int,int>> c;
        int x=v[i].first;
        int y=v[i].second;
        vis[x][y]=true;
        c.emplace_back(x,y);
        back_track(1,c, 1,0,vis,x,y);
        vis[x][y]=false;
    }
    cout << SumP.size();
}