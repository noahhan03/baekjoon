#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string str;
    int ans=0;
    cin >> str;
    stack<char> s;
    for(int i=0;i<str.length();i++){
        char cur=str[i];
        if(cur=='('){
            s.push(cur);
        }
        else {
            if(str[i-1]=='('){
                s.pop();
                ans+=s.size();
            }
            else {
                s.pop();
                ans++;
            }
        }
    }
    cout << ans;
}