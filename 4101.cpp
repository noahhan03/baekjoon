#include<iostream>
using namespace std;
int main(){
    int a,b;
    cin >> a >> b;
    while(a && b){
        if(a>b)cout<<"Yes\n";
        else cout<<"No\n";
        cin >> a >> b;
    }
}