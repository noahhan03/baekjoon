#include<iostream>

using namespace std;

long long int f(long long int a)
{
    while(a){
        if(a%10==6){
            a/=10;
            if(a%10==6){
                a/=10;
                if(a%10==6)return 1;
            }
        }
        a/=10;
    }
    return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    long long int k;
    cin >> n;
    if(n<=6){
        cout << 666+1000*(n-1);
    }
    else{
        n-=6;
        k=5666;  
        while(n){
            k++;
            if(f(k))n--;
        }
        cout << k;
    }
}