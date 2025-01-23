#include<iostream>
#include<queue>

using namespace std;

bool chk[1000];

int main(){
    int n,k;
    queue<int> q;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        q.push(i+1);
    }
    while(1){
        int cur+=n;
        cout << q[cur]<<" ";
        q.pop
    }
}