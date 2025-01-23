#include<iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,a,k;
    cin >> n;
    if(n==1){
        cin >> a;
        cout << a*a;
    }
    else {
        a=1;
        for(int i=0;i<n;i++)
        {
            cin >> k;
            a=k*a;
        }
        cout << a;
    }
}