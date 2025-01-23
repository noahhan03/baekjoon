#include<iostream>
using namespace std;

int arr[100001];

int main(){
    int n,k,z;
    cin >> n >> k;
    cin >> arr[0];
    for(int i=1;i<n;i++){
        cin >> z;
        arr[i]=arr[i-1]+z;
    }
    int res=arr[k-1];
    for(int i=k;i<n;i++){
        z=arr[i]-arr[i-k];
        if(z>res)res=z;
    }
    cout << res;
}