#include<iostream>
#include<string>
#include<queue>
#include<vector>

using namespace std;

struct Compare {
    bool operator()(const string& a, const string& b) {
        if (a.length() == b.length()) {
            return a > b; // 길이가 같다면 사전순
        }
        return a.length() > b.length(); // 길이가 짧은 순
    }
};

int main(){
    priority_queue< string,vector<string> , Compare > pq[12];
    int n,m;
    cin >> n >>m;
    while(1){
        int num;
        string name;
        cin >> num >> name;
        if(!num)break;
        if(pq[num].size()<m)pq[num].push(name);
    }
    for(int i=1;i<=n;i+=2){
        int l=pq[i].size();
        for(int j=0;j<l ;j++){
            cout<< i <<" "<<pq[i].top()<<"\n";
            pq[i].pop();
        }
    }
    for(int i=2;i<=n;i+=2){
        int l=pq[i].size();
        for(int j=0;j<l;j++){
            cout<< i <<" "<<pq[i].top()<<"\n";
            pq[i].pop();
        }
    }   
}