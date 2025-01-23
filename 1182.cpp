#include<iostream>

using namespace std;

int n,s,ans,arr[21];

void back_track(int size,int cnt, int sum , int idx ){
    if(size==cnt){
        if(sum==s){
            // cout << "idx : "<< idx <<" size : "<< size <<"\n";
            ans++;
        }
        return;
    }
    if((idx)>=n)return;

    back_track(size, cnt+1, sum+arr[idx], idx+1);
    back_track(size, cnt, sum , idx+1);
}

int main(){
    cin >> n >> s;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    for(int i=1;i<=n;i++){
        back_track(i,0,0,0);
    }
    cout << ans ;
}