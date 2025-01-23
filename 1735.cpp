#include<iostream>

using namespace std;

int GCD(int a, int b){
  return b ? GCD(b, a % b) : a;
}

int main()
{
    int a,b,x,y,z;
    int n,m;
    cin >> a >> b >> x >> y;
    n=a*y+b*x;
    m=b*y;
    z=GCD(n,m);
    cout << n/z << " " << m/z ;
}