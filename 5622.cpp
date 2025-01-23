#include<iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cnt=0;
    string str;
    cin >> str;
    for(int i=0;i<str.length();i++){
        char c=str[i];
        if(64<c && c<68){
            cnt=cnt+3;
        }
        else if(67<c && c<71){
            cnt=cnt+4;
        }
        else if(70<c && c<74){
            cnt=cnt+5;
        }
        else if(73<c && c<77){
            cnt=cnt+6;
        }
        else if(76<c && c<80){
            cnt=cnt+7;
        }
        else if(79<c && c<84){
            cnt=cnt+8;
        }
        else if(83<c && c<87){
            cnt=cnt+9;
        }
        else if(86<c && c<91){
            cnt=cnt+10;
        }
    }
    cout << cnt;
}