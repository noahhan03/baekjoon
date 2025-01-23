#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int main(){
    int n,l=0;
    vector<pair<int,int>> v;
    cin >> n;
    for(int i=0;i<n;i++){
        int t,s;
        cin >> t >> s;
        v.emplace_back(t,s);
    }
    sort(v.begin(),v.end());
}
