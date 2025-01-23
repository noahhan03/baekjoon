#include<iostream>

using namespace std;

int main()
{
    int t;
    int n;
    string s;
    cin >>t;
    for(int i=0;i<t;i++){
        cin >> n;
        cin >> s;
        for(int j=0;j<s.length();j++){
            for(int k=0;k<n;k++){
                cout<<s[j];
            }
        }
        cout <<"\n";
    }
}