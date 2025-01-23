#include<iostream>
#include<queue>
#include<string>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    queue<int> q;
    cin >> n;
    for(int i=0;i<n;i++){
        string cm;
        cin >> cm;
        if(cm=="push"){
            int x; 
            cin>> x;
            q.push(x);
        }
        if(cm=="pop"){
            if(q.empty()){
                cout <<"-1\n";
            }
            else {
                cout << q.front()<<"\n";
                q.pop();
            }
        }
        if(cm=="size")cout<<q.size()<<"\n";
        if(cm=="empty")cout<<q.empty()<<"\n";
        if(cm=="front"){
            if(q.empty())cout<<"-1\n";
            else cout<<q.front()<<"\n";
        }
        if(cm=="back"){
            if(q.empty())cout<<"-1\n";
            else cout<<q.back()<<"\n";
        }
    }
}