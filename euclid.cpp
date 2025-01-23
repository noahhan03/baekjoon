#include<iostream>

using namespace std;

int gcd(int a,int b)
{
    if(b==0){
        return a;
    }
    else {
        return gcd(b,a%b);
    }
}

int lcm(int a,int b)
{
    return a*b/gcd(a,b);
}

int main()
{
    int a=10;
    int b=6;
    cout << gcd(a,b) <<"\n" << lcm(a,b);
}