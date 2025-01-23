#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
    string num="";
    string str;
    int sum=0;
    bool beforeM=false;
    cin >> str ;
    for(int i=0;i<=str.length();i++){
        if(str[i]=='-' || str[i]=='+' || i==str.size()){
            if(beforeM){
               sum-=stoi(num);
               num=""; 
            }
            else {
                sum+=stoi(num);
                num="";
            }
        }
        else {
            num+=str[i];
        }
        if(str[i]=='-')beforeM=true;
    }
    cout << sum;
}