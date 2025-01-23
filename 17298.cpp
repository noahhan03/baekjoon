#include<iostream>
#include<stack>

using namespace std;

int out[1000010];
int arr[1000010];


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,t;
    stack<pair<int,int>> s;
    stack<int> index;
    cin>> n;
    for(int i=0;i<n;i++){
        cin >> t;
        arr[i]=t;
        if(!i)s.emplace(t,i);
        while(!s.empty()){
            int cur_value=s.top().first;
            int cur_index=s.top().second;
            if(cur_value<t){
                s.pop();
                out[cur_index]=t;
                
            }
            else {
                break;
            }
        }
        s.emplace(t,i);
    }
    for(int i=0;i<n;i++){
        if(out[i])cout<<out[i]<<" ";
        else cout<<"-1 ";
    }
}