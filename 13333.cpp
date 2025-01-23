#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int a[1001];
    int st,en,x;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    sort(a,a+n);
    for(int i=n;i>=0;i--){
        if(a[n-i]<=i){
            cout<< i;
            break;
        }
    }
}