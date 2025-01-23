#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        string x; 
        cin >> x;
        int len=x.length();
        if(len>5&&len<=10)cout<<"yes\n";
        else cout<<"no\n";
    }
}