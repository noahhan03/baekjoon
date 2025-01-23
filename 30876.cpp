#include<iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,min=1001;
    int x,y,c,d;
    cin >>n;
    for(int i=0;i<n;i++){
        cin >> x >> y;
        if(min>y){
            min=y;
            c=x;
            d=y;
        }
    }
    cout <<c<<" "<<d;
}