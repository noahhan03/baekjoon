#include<iostream>
#include<string>

using namespace std;

int main()
{
    string str;
    int st=0,en,chk=1;
    cin >> str;
    en=str.length()-1;
    while(st<=en){
        if(str[st]!=str[en]){
            chk=0;
        }
        st++;
        en--;
    }
    if(chk)cout << chk;
    else cout << chk;
}