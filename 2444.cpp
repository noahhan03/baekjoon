#include<iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=n;j>i;j--){
            cout <<" ";
        }
        for(int j=1;j<=2*i-1;j++){
            cout <<"*";
        }
        cout <<"\n";
    }
    for(int i=n-1;i>=1;i--){
        for(int j=n;j>i;j--){
            cout <<" ";
        }
        for(int j=1;j<=2*i-1;j++){
            cout <<"*";
        }
        cout <<"\n";
    }
}