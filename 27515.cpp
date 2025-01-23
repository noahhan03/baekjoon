#include<iostream>

using namespace std;

int ar[63]; 
int cnt;

int f();
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q;
    int a;
    cin >> q;
    for(int i=0;i<q;i++)
    {
        cin >> a;
        if(a>=0){
            ar[a]++;
            cnt++;
        }
        else{
            ar[a]--;
            cnt--;
        }
        cout << f() <<"\n";
    }
}
int f()
{
    if(cnt)
    {
        ;
    }
    else return 0;
}