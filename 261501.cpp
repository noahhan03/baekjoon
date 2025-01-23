#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<pair<int,char>> v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,a,b;
    char str[1001],c;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> str >> a >> b;
        c=str[b-1];
        v.push_back(pair<int,char>(a,c));
    }
    sort(v.begin(),v.end());   
    for(int i=0;i<n;i++){
        if(96<v[i].second && v[i].second<123)v[i].second=v[i].second-32;
        cout << v[i].second;
    }
}