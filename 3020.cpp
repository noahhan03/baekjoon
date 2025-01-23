#include<iostream>
#include<algorithm>

using namespace std;

int n,h;
int up[200010];
int down[200010];

void setup(int k){
    for(int i=h;i>(h-k);i--)up[i]++;
}

void setdown(int k){
    for(int i=1;i<=k;i++)down[i]++;
}

int main(){
    cin >> n >> h;
    for(int i=1;i<=n;i++){
        int x;cin >> x;
        if(i%2){
            down[x]++;
        }
        else up[h-x+1]++;
    }
    for(int i=1;i<=h;i++){
        up[i]+=up[i-1];
        down[h-i]+=down[h-i+1];
    }
    int min=2e9;
    int cnt=0;
    for(int i=1;i<=h;i++){
        int tmp=down[i]+up[i];
        if(tmp<min){
            min=tmp;
            cnt=1;
        }
        else if(tmp==min)cnt++;
    }
    cout << min <<" "<<cnt;
}