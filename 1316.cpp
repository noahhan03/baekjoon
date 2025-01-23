#include<iostream>
#include<string>
using namespace std;

int group(string s)
{
    int len=s.length();
    int last[132][2]={0,}; //[][0]-last loc, [][1]-cnt
    last[s[0]][1]++;
    for(int i=1;i<s.length();i++){
        int cur=s[i];
        //cout <<"last[cur][0] : "<<last[cur][0]<<" last[cur][1]-cnt : "<<last[cur][1]<<endl;
        if(last[cur][0]!=(i-1) && last[cur][1]){
            //cout <<"0 : "<<s[i]<<"i : "<<i<<endl;
            return 0;
        }
        else {
            //cout <<"? : "<<s[i]<<endl;
            last[cur][0]=i;
            last[cur][1]++;
        }
    }
    return 1;
}
int main()
{
    int n;
    int cnt=0;
    std::string str;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> str;
        if(group(str))cnt++;
    }
    cout << cnt;
}