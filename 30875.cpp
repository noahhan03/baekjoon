#include<iostream>
using namespace std;
int main()
{
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> x;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout <<(i%2)+1 <<" ";
        }
        cout <<endl;
    }
}