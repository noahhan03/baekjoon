#include<iostream>

using namespace std;

int main(){
    int k=0,d=0;
    char chr;
    cin >> chr;
    while(chr!='h'){
        k++;
        cin >> chr;
    }
    cin >> chr;
    while(chr!='h'){
        d++;
        cin >> chr;
    }
    if(k<d)cout<<"no";
    else cout<<"go";
}