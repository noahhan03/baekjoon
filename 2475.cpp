#include<iostream>
using namespace std;
int x,i,t;
int main(){
    for(;i<5;i++){
        cin>>t;
        x+=t*t;
    }
    cout<<x%10;
}