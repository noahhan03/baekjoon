#include<iostream>
#include<stack>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    stack<pair<int,int>> s;
    cin >> n;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        while(!s.empty()){
            int bef=s.top().first;
            int idx = s.top().second;
            if(bef>x){
                cout << idx << " ";
                break;
            }
            s.pop();
        }
        if(s.empty()){
            cout << "0 ";
        }
        s.emplace(x,i);
    }
}