#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<queue>

using namespace std;

int n,m;
int cls_x;
int cls_y;
vector<pair<int,int>> ice;
bool vis[310][310];
int temp[310][310];
int map[310][310];
int mm[310][310]; //빙산 덩어리 확인용 배열
bool vis_cnt[310][310];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
vector<pair<int,int>> ice_cls;

void bfs_cnt(int ii,int jj){
    queue<pair<int,int>> q;
    q.emplace(ii,jj);
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=0 && nx<n && ny>=0 &&ny<m &&vis_cnt[nx][ny]==0 && map[nx][ny]){
                vis_cnt[nx][ny]=1;
                q.emplace(nx,ny);
            }
        }
    }
}

int icecnt(){
    int cnt=0;
    // 빙산이 두덩어리 이상으로 분리되었는지 확인 
    for(int i=0;i<ice.size();i++){
        int x=ice[i].first;
        int y=ice[i].second;
        if(vis_cnt[x][y]==0){
            bfs_cnt(x,y);
            vis_cnt[x][y]=1;
            cnt++;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            vis_cnt[i][j]=0;
            temp[i][j]=0;
        }
    }
    return cnt;
}

void bfs(){
    queue<pair<int,int>> q;
    for(int i=0;i<ice.size();i++){
        int x=ice[i].first;
        int y=ice[i].second;
        q.emplace(x,y);
    }
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=0 && nx<n && ny>=0 && ny<m && map[nx][ny]==0)temp[x][y]++;
        }
    }
    for(int i=0;i<ice.size();i++){
        int x=ice[i].first;
        int y=ice[i].second;
        cls_x=x;
        cls_y=y;
        map[x][y]-=temp[x][y];
        // cout<<"temp["<<x<<"]["<<y<<"] = "<<temp[x][y]<<endl;
        if(map[x][y]<=0){
            map[x][y]=0;
            ice_cls.emplace_back(x,y);
        }
    }
    for(int i=0;i<ice_cls.size();i++){
        cls_x=ice_cls[i].first;
        cls_y=ice_cls[i].second;
        ice.erase( remove_if(ice.begin(), ice.end(), [](const pair<int, int>& p) {return p.first == cls_x && p.second == cls_y;}), ice.end() );
    }
    ice_cls.erase(ice_cls.begin(), ice_cls.end());
}

void print();


int main(){
    int year=0;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> map[i][j];
            mm[i][j]=map[i][j];
            if(map[i][j])ice.emplace_back(i,j);
        }
    }
    while(1){
        year++;
        bfs();
        // print(); 
        int iceGcnt=icecnt();
        if(iceGcnt>=2)break;
        if(iceGcnt==0){
            year=0;
            break;
        }
    }
    cout << year << endl;
}



void print(){
    int kk;
    cin >> kk;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout <<map[i][j]<<" ";
        }
        cout << endl;
    }
}