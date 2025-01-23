#include<iostream>
using namespace std;

int zero[41];
int one[41];
bool zero_chk[41];
bool one_chk[41];


int o(int n){
    if(one_chk[n])return one[n];
    else {
        one[n]=o(n-1)+o(n-2);
        one_chk[n]=1;
        return one[n];
    }
}
int z(int n){
    if(zero_chk[n])return zero[n];
    else {
        zero[n]=z(n-1)+z(n-2);
        zero_chk[n]=1;
        return zero[n];
    }
}

int main(){
    int t;
    cin >> t;
    one_chk[0]=1;
    zero_chk[0]=1;
    zero_chk[1]=1;
    one_chk[1]=1;
    zero[0]=1;
    one[0]=0;
    zero[1]=0;
    one[1]=1; 
    for(int i=0;i<t;i++){
        int n;
        cin >> n;
        cout << z(n) <<" "<< o(n) <<"\n";
    }
}