#include<iostream>
#include<queue>
#include<vector>


using namespace std;

int main(){
    int n;
    cin >> n;
    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq;
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        pq.emplace(a,b);
    }
    for(int i=0;i<n;i++){
        cout << pq.top().first <<" "<<pq.top().second<<"\n";
        pq.pop();
    }
}