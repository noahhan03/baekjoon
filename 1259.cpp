#include<iostream>

using namespace std;


int f(int a)
{
    int cnt=0,arr[8],st=0,en;
    while(a!=0){
        arr[cnt++]=a%10;
        a/=10;
    }
    en=cnt-1;
    cnt=1;
    while(st<=en){
        if(arr[st]!=arr[en]){
            cnt=0;
            break;
        }
        st++;
        en--;
    }
    return cnt;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k;
    cin >> k;
    while(k!=0){
        if(f(k)){
            cout <<"yes\n";
        }
        else cout <<"no\n";
        cin >> k;
    }
}