#include<iostream>
using namespace std;

int main()
{
    int n,m,cnt,remain;
    cin >> n >> m;
    cnt=n/m;
    cout << cnt<<"\n";
    remain=n-m*cnt;
    cout<<remain;
}