#include<iostream>

using namespace std;

int main(){
    int n,cnt=0;
    cin >> n;
    int before=n%2;
    int k;
    n/=2;
    if(before==0)cnt++;
    while(n>0){
        k=n%2;
        n/=2;
        if(k==0 && before==1){
            cnt++;
        }
        before=k;
    }
    cout << cnt;
}