#include<iostream>
#include<string>

using namespace std;

int main()
{
    int cnt=0;
    string s;
    cin >> s;
    cnt=s.length();
    for(int i=0;i<s.length();i++){
        if(s[i]=='c'&& (s[i+1]=='-' || s[i+1]=='=')){
            cnt--;
            i++;
        }
        if(s[i]=='d'&&s[i+1]=='z' && s[i+2]=='='){
 
            cnt-=2;
            i+=2;
        }
        if(s[i]=='d' && s[i+1]=='-'){
            
            cnt--;
            i++;
        }
        if(s[i]=='l' && s[i+1]=='j'){
            
            cnt--;
            i++;
        }
        if(s[i]=='n' && s[i+1]=='j'){
            cnt--;
            i++;
        }
        if(s[i]=='s' && s[i+1]=='='){
            cnt--;
            i++;
        }
        if(s[i]=='z' && s[i+1]=='='){
            cnt--;
            i++;
        }
    }
    cout << cnt;
}