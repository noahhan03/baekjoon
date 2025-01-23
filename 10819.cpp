#include<iostream>
#include<vector>

using namespace std;

int n, arr[9];
vector<int> v;
int maxx;
bool vis[9];
void sol(){
    if(n==v.size()){
        int sum=0;
        for(int i=0;i<n-1;i++){
            sum+=abs(v[i]-v[i+1]);
        }
        if(maxx<sum)maxx=sum;
    }
    for(int i=0;i<n;i++){
        if(!vis[i]){
            vis[i]=true;
            v.push_back(arr[i]);
            sol();
            v.pop_back();
            vis[i]=false;
        }
    }
}

int main(){
    cin >>n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    sol();
    cout << maxx;
}