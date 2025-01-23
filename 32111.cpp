#include<iostream>
#include<vector>
#include<stack>

using namespace std;

stack<char> s;
char map[500010];
bool chk[500010];


void sol(int n){
    int sum=0;
    stack<char> tm;
    while(!s.empty()){
        char cur = s.top();
        s.pop();
        if(sum==0 && cur=='O'){
            tm.push('+');
            sum++;
        }
        if(sum==0 && cur=='X'){
            tm.push('-');
            sum--;
        }
    }
}

int main(){
    int n;
    int cntSnow=0;
    int cntD=0;
    int tag;
    bool flag=true;
    vector<char> v;
    cin >> n;
    for(int i=0;i<n;i++){
        char tmp;
        cin >> tmp;
        if(tmp=='O'){
            map[i]='+';
            cntSnow++;
            tag=i;
        }
        else cntD++;
        if(cntD>1 && tmp=='X' && cntSnow>0){
            if(v[i-1]=='X' && tag==(i-2)){
                flag=false;
            }
            chk[i-2]=true;
        }
        s.push(tmp);
        v.push_back(tmp);
    }
    if(v[n-1]=='X' && v[n-2]=='O' && v[0]=='X'){
        flag=false;
    }
    if(v[0]=='X' && v[1]=='X' && v[n-1]=='O')flag=false;
    if(flag){
        cout <<"YES\n";
        for(int i=0;i<n;i++){
            if(map[i]!='+')cout <<"-";
            else cout<<map[i];
        }
    }
    else {
        cout <<"NO";
    }
}