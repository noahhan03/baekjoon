#include<iostream>

using namespace std;

int work[1010][1010];
bool chk[1010];
int task_num[1010];

int main(){
    int n;int m;int ans=0,int less=1001,int less_num;
    cin >>n >> m;
    for(int i=1;i<=n;i++){
        int many;
        int task;
        for(int j=0;j<many;j++){
            cin >> task;
            work[i][task]=1;
            task_num[i]++;
        }
        if(less>many){
            many=less;
            less_num=i;
        }
        if(many==1){
            chk[task]=1;
            ans++;
        }
    }
}