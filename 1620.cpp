#include<iostream>
#include<string>
#include<cstring>
#include<map>
using namespace std;
int main(){
    cin.tie(0); ios::sync_with_stdio(0);
    string f;
    map<string,int> pedia;
    string pp[100002];
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> f;
        pedia.insert(pair<string,int>(f,i));
        pp[i]=f;
    }
    for(int i=0;i<m;i++){
        cin >> f;
        if(isdigit(f[0]) != 0){
            int x=stoi(f);
            cout << pp[x] << "\n";
        }
        else {
            cout << pedia.find(f)->second << "\n";
        }
    }
}