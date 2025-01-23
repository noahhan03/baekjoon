#include<iostream>
#include<algorithm>
#include<tuple>
#include<vector>

using namespace std;

vector<pair<int,int>> v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,d[101];
    char s[101][101];
    char res[101];
    int a,b;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> s[i] >> a >> d[i];
        v.push_back(pair<int,int>(a,i));
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++)
    {
        res[i]=s[v[i].second][d[v[i].second]-1];
        if(96<res[i] && res[i]<123)res[i]=res[i]-32;
    }
    cout << res<<"\n";
}