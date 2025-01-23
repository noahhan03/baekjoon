#include<iostream>

using namespace std;

long long int p(int r ,  int n)
{
    long long int res =1 ;
    int rr=1;
    for(int i=r;i>r-n;i--){
        res*=i;
        res/=rr;
        rr++;
    }
    return res;
}

int main()
{
    int t;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        int n,r;
        cin >> r >> n;
        cout << p(n,r) <<endl;
    }
}
