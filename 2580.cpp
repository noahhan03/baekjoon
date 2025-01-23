#include<iostream>
#include<vector>
using namespace std;

int ma[9][9], out=0;
vector<pair<int,int>> v;

bool possible(int x, int y, int val, int map[9][9]){
    // 세로 규칙 
    int xx=x-1;
    while (xx>=0)
    {
        if(map[xx][y] && map[xx][y]==val)return false;
        xx--;
    }
    xx=x+1;
    while(xx<9){
        if(map[xx][y] && map[xx][y]==val)return false;
            xx++;
    }
    // 가로 규칙 
    int yy=y-1;
    while(yy>=0){
        if(map[x][yy] && map[x][yy]==val)return false;
        yy--;
    }
    yy=y+1;
    while(yy<9){
        if(map[x][yy] && map[x][yy]==val)return false;
        yy++;
    }
    xx=(x/3)*3, yy=(y/3)*3;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(map[xx+i][yy+j] && map[xx+i][yy+j]==val)return false;
        }
    }
    return true;
}

void back_track(int cnt, int size, int idx, int map[9][9]){
    if(out)return ;
    if(cnt == size){
        out =1;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout << map[i][j]<<" ";
            }
            cout << "\n";
        }
        return ;
    }
    if(idx>=size)return ;
    for(int i=1;i<=9;i++){
        int x=v[idx].first;
        int y=v[idx].second;
        if(possible(x,y,i,map)){
            map[x][y]=i;
            back_track(cnt+1, size, idx+1, map  );
            map[x][y]=0;
        }
    }
}

int main(){
    int map[9][9];
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin >> map[i][j];
            ma[i][j]=map[i][j];
            if(!map[i][j])v.emplace_back(i,j);
        }
    }
    // cout << "v.size() " <<v.size()<<"\n";
    back_track(0,v.size(), 0, map );
}