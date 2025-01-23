#include<iostream>
using namespace std;
int m[1001];
int arr[1001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        if(x<0)m[-x]=1;
        else arr[x]=1;
    }
    for(int i=1001;i>0;i--){
        if(m[i])cout<<-i<<" ";
    }
    for(int i=0;i<1001;i++){
        if(arr[i])cout <<i<<" ";
    }
}