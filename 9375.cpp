#include<iostream>
#include<map>
#include<string>
using namespace std;

int main(){
    int t;
    int hmm;
    string a,b;
    cin >> t;
    for(int i=0;i<t;i++){
        int n;
        map<string,int> m;
        cin >> n;
        for(int j=0;j<n;j++){
            cin >> a >> b;
            m[b]++;
        }
        hmm=1;
        for(map<string,int>::iterator it=m.begin();it!=m.end();it++)
        {
            hmm *= ((*it).second+1);
        }
        cout << hmm-1;
    }
}