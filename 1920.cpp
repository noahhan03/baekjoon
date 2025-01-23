#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,arr[100001],m,k;
    cin >> n;
    for(int i=0;i<n;i++)cin >> arr[i];
    cin >> m; 
    sort(arr,arr+n);
    for(int i=0;i<m;i++)
    {
        cin >> k;
        if(binary_search(arr,arr+n,k))cout << "1\n";
        else cout << "0\n";
    }
}