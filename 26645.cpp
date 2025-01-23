#include<iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if(n>229)cout << "4";
    else if(n>=221)cout << "3";
    else if(n>=213)cout <<"2";
    else cout<<"1";
}