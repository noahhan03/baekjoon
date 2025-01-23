#include<iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int max=0,x,k;
    for(int i=0;i<9;i++)
    {
        cin >> k;
        if(k>max){
            max=k;
            x=i+1;
        }
    }
    cout << max << "\n" << x;
}