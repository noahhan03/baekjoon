#include<iostream>
#include<string>

using namespace std;

int s[21];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m;
    cin>> m;
    for(int i=0;i<m;i++){
        string cmd;int x;
        cin >> cmd;
        if(cmd=="add"){
            cin >> x;
            s[x]=1;
        }
        if(cmd=="remove"){
            cin >> x;
            s[x]=0;
        }
        if(cmd=="check"){
            cin >> x;
            if(s[x])cout<<"1\n";
            else cout<<"0\n";
        }
        if(cmd=="toggle"){
            cin >> x;
            s[x]=!s[x];
        }
        if(cmd=="all"){
            std::fill_n(s, 21, 1); 
        }
        if(cmd=="empty"){
            std::fill_n(s, 21, 1);
        }
    }
}