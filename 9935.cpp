#include<iostream>
#include<string>
#include<stack>

using namespace std;


bool chk(string bo, string t){
    if(bo.length()!=t.length())return false;
    for(int i=0;i<bo.length();i++){
        if(bo[i]==t[i])continue;
        else return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string res;
    string ss;
    string bomb;
    string tt;
    stack<char> s;
    stack<char> temp;
    int idx=0;
    cin >> ss >> bomb;
    int idxB=bomb.length();
    for(int i=0;i<ss.length();i++){
        int flag=0;
        for(int j=0;j<idxB;j++){
            if(ss[i]==bomb[j]){
                flag=1;
                s.push(ss[i]);
                if(j==idxB-1){
                    int Idx=j;
                    while(Idx>=0){
                        tt[Idx]=s.top();
                        s.pop();
                        Idx--;
                    }
                    if(chk(bomb,tt)){
                        tt.clear();
                    }
                    else {
                        res.append(tt);
                        tt.clear();
                    }
                }
            }
        }
        if(!flag)res.push_back(ss[i]);
    }
    if(res.empty()){
        cout <<"FRULA";
    }
    else cout<< res;
}