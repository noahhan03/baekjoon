#include<iostream>
#include<map>
using namespace std;

map <string, int> m;

int cnt;

int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        string name;
        cin >> name;
        m[name]++;
    }
    for(auto p : m) cnt = max(cnt, p.second);
    for(auto p : m){
        if(p.second == cnt){
            cout << p.first; 
            return 0;
        }
    }
}