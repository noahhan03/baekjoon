#include<iostream>

using namespace std;

void sol(){
    int h,w,n;
    int cur_flow=1;
    int cur_num=1;
    cin>> h >> w >> n;
    while(1){
        if(n>h){
            cur_num++;
            n-=h;
        }
        else {
            n--;
            cur_flow++;
            if(!n)break;
            
        }
    }
    cur_flow--;
    
    cout << cur_flow*100+cur_num <<"\n";
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin>> T;
    for(int i=0;i<T;i++){
        sol();
    }
}