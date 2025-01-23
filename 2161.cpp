#include<iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int arr[1001];
    int n;
    cin >> n;
    for(int i=0;i<n;i++)arr[i]=i+1;
    while (n)
    {
        cout <<arr[0]<<" ";
        n--;
        for(int i=0;i<n;i++)arr[i]=arr[i+1];
        int z=arr[0];
        for(int i=0;i<n;i++)arr[i]=arr[i+1];
        arr[n-1]=z;
    }
}