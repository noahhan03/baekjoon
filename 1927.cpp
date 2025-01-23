#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    priority_queue<int,vector<int>,greater<int>> pq;
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        if(x){
            pq.push(x);
        }
        else {
            if(pq.empty())cout<<"0\n";
            else {
                cout << pq.top()<<"\n";
                pq.pop();
            }
        }
    }
}