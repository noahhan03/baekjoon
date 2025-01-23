#include<iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,max,min,k;
    cin >> n;
    cin >> k;

    max=k;min=k;

    for(int i=1;i<n;i++)
    {
        cin >>k;
        if(max<k)max=k;
        if(min>k)min=k;
    }

    cout << min << " " << max;
}