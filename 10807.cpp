#include<iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n, v, arr[102],cnt=0;
    cin >> n;
    for(int i=0;i<n;i++)cin >> arr[i];
    cin >> v;
    for(int i=0;i<n;i++)
    {
        if(v==arr[i])cnt++;
    }
    cout << cnt;
}