#include<iostream>

#define ll long long

using namespace std;
int n,cnt;

ll xx=-1;


void back_track(ll num, int step){
    char bb;
    // cout << "num : "<<num <<" step : "<<step<<"\n";
    // cin >> bb;
    if(!step){
        if(cnt==n)xx=num;
        // cout << "cnt " << cnt <<"\n";
        // cin >> bb;
        cnt++;
        return;
    }

    int last = num % 10;
    if(num == 0) last = 10;
    // cout <<"last : "<<last <<"cnt : "<<cnt <<"\n";
    // cin >>bb;
    for (int i=0;i<last;i++) {
        ll nextNum = (num * 10) + i;
        if(num == 0 && i == 0) continue;

        back_track(nextNum, step - 1);
    }
}




int main(){
    cin >> n;
    if(n>1022)cout <<"-1";
    else {
    for(int i=0;i<=10;i++){
        back_track(0,i);
    }
    cout << xx;
    }
}