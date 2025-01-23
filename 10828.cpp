#include<iostream>
#include<stack>
#include<string>

using namespace std;
int main(){
    stack<int> s;
    string cm;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> cm;
        if(cm=="push"){
            int x;
            cin >> x;
            s.push(x);
        }
        if(cm=="pop"){
            if(!s.empty()){
                cout << s.top()<<endl;
                s.pop();
            }
            else cout<<"-1"<<endl;
        }
        if(cm=="size")cout<<s.size()<<endl;
        if(cm=="empty"){
            if(s.empty())cout<<"1"<<endl;
            else cout<<"0"<<endl;
        }
        if(cm=="top"){
            if(!s.empty()){
                cout << s.top()<<endl;
            }
            else cout<<"-1"<<endl;
        }
    }
}