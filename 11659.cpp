#include<iostream>

using namespace std;

int arr[100002];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,st=0,k;
    int a,b;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> k;
        st= k + st;
        arr[i]=st;
    }
    for(int i=0; i< m;i++)
    {
        cin >> a >> b ;
        cout << arr[b]-arr[a-1] <<"\n";
    }
}