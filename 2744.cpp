#include<iostream>
#include<string>
using namespace std;
int main(){
    char str[101];
    cin >> str;
    for(int i=0;str[i]!='\0';i++){
        char t;
        if(str[i]<92){
            t=str[i]+32 ;
        }
        else t= str[i]-32;
        cout << t;
    }
}