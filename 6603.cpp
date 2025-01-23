#include<iostream>

using namespace std;

int arr[15];

void back_track(int k, int Parr[], int cnt , int idx){
    if(cnt==6){
        for(int i=0;i<6;i++){
            cout << Parr[i]<<" ";
        }
        cout << "\n";
        return ;
    }
    if(idx >=k)return ;
    Parr[cnt]=arr[idx];
    idx++;
    back_track(k, Parr, cnt+1, idx);
    back_track(k, Parr, cnt, idx);
}

void sol(int k){
    for(int i=0;i<k;i++)cin >> arr[i];
    int tmp[15];
    back_track(k,tmp, 0, 0);
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int k=1;
    while(k){
        cin >> k;
        sol(k);
    }
}