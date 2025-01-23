#include<iostream>

using namespace std;

int ans=0;
int score[6];
void solve(int cnt, int w, int val) {
if(w > 15) return;
if((cnt<=3 && w<=10) || (cnt>=4 && w<=15)) ans = max(ans, val);
for(int i=1; i<=5; i++) { solve(cnt+1, w+i, val+score[i]); }
}
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
for(int i=1; i<=5; i++) {
cin >> score[i];
}
solve(0, 0, 0);
cout << ans;
}