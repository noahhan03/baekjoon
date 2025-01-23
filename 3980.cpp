#include<iostream>
#include<map>

using namespace std;

int maxx =0; // 능력치 최대합
// int arr[11][11]; // 선수 정보
//cur - 현재 정하고 있는 포지션, sum - 이렇게 정했을 때 능력치 총합 ,map- 이미 배정된 선수 명단
void BackTrack(int cur, int sum, bool pp[11],int arr[11][11]){
    if(cur>10 ){
        if(maxx<sum)maxx=sum;
        return;
    }
    for(int num=0;num<11;num++){
        if(!pp[num] && arr[num][cur]){
            int temp=sum+arr[num][cur];
            pp[num]=true;
            BackTrack(cur+1, temp, pp,arr);
            pp[num]=false;
        }
    }
}

void test(){
    bool p[11];
    int arr[11][11];
    for(int num=0;num<11;num++){
        for(int j=0;j<11;j++){
            cin >> arr[num][j];
        }
    }
    for(int i=0;i<11;i++){
        if(arr[i][0]){
            p[i]=true;
            BackTrack(1, arr[i][0], p,arr);
            p[i]=false;
        }
    }
    cout << maxx <<"\n";
    maxx=0;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int C;
    cin >> C;
    for(int i=0;i<C;i++){
        test();
    }
}