#include<iostream>
#include<string>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string a,b;
    cin >>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        for(int j=0;j<a.length();j++){
            if(a[j]=='x'||a[j]=='X'){
                char x;
                if(b[j]>96&&b[j]<123)x=b[j]-32;
                else x=b[j];
                cout <<x;
                break;
            }
        }
    }
}