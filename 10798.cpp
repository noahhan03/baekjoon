#include<iostream>
#include<string>
#include<cstring>

using namespace std;

int main()
{
    char str[6][20];
    int max_len=0;
    for(int i=0;i<5;i++){
        cin >> str[i];
        if(max_len<strlen(str[i]))max_len=strlen(str[i]);
    }
    for(int j=0;j<max_len;j++){
        for(int i=0;i<5;i++){
            if(j<strlen(str[i]))cout << str[i][j];
        }
    }
}