#include<iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int x=0,n,a,b,money=0;
    cin >> x;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a >> b;
        money=money + a*b;
    }
    if(x==money)cout << "Yes";
    else cout << "No";
}