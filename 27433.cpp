#include<iostream>

using namespace std;

int main(){
    long long res=1;
    int n;
    cin >> n;
    if(n==0 || n==1)cout << "1";
    else {
        for(int i=2;i<=n;i++){
            res*=i;
        }
        cout << res;
    }
}