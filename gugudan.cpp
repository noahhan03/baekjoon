#include<iostream>

using namespace std;

int main()
{
    long long n;
    cout <<"단을 입력하시오 : ";
    cin >> n; 
    for(long long i=1;i<=9;i++)
    {
        cout << i <<" x " << n <<" = " << i*n <<endl;
    }
    return 0;
}