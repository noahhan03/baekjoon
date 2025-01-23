#include<iostream>
#include<map>
#include<string>
using namespace std;
int main(){
    string s;
    map<string,int> m;
    cin >> s;
    int len=s.length();
    for(int i=0;i<len;i++){
        string input;
        input=s.substr(i,len);
        m.insert(pair<string,int>(input,i));
    }
    for(map<string,int>::iterator it=m.begin();it!=m.end();it++){
        cout << it->first << endl;
    }
}