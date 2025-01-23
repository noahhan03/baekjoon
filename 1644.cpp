#include<iostream>
#include<vector>

using namespace std;

vector<int> v;

bool chk(int n){
    for(int i=2;i<n/2;i++){
        if(n%i==0)return false;
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    v.push_back(2);
    v.push_back(3);
    v.push_back(5);
    v.push_back(7);
    v.push_back(11);
    for(int i=12;i<=n;i++){
        if(chk(i))v.push_back(i);
    }
    for(int size=1;size<=n;size++){
        for(int st=0;st+size<=n;st++){
            ;
        }
    }
}