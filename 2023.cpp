// Created on iPad.

#include <iostream>
#include<vector>
using namespace std;

int n;
int cnt;
vector<int> box;

bool check(int x){
    for(int i=2;i<x;i++){
        if(x%i==0)return false;

    }
    return true;
}

void backtrack(int size,int num)
{
    if(n==size && check(num)){
        cnt++;
        box.push_back(num);
        return ;
    }

    for(int i=1;i<=9;i+=2){
        if(check(i+num*10)){
            
            backtrack(size+1, num*10+i);
        }
    }
}

int main() {
    cin >> n; // n자리 수의 신기한 소수
    for(int i=2;i<=7;i++){
        if(check(i)){
            backtrack(1,i);
        }
    }
    for(int i=0;i<box.size();i++){
        cout << box[i]<<"\n";
    }
}