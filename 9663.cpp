#include<iostream>
using namespace std;

int cnt=0;
int column[16];

bool isFine(int lev){
    for(int i=0;i<lev;i++)
    {
        if(column[i]==column[lev] || abs(column[i]-column[lev])==abs(i-lev) ){
            return false;
        }
    }
    return true;
}

void bfs(int n,int cur){
    if(cur==n){
        cnt++;
    }
    else {
        for(int i=0;i<n;i++){
            column[cur]=i;
            if(isFine(cur)){
                bfs(n,cur+1);
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    bfs(n,0);
    cout << cnt;
}