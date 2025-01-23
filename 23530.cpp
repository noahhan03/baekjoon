#include<iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    int a,b,c;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        cin >> a >> b;
        c=a+b/2;
        cout << c << "\n";
    }
}