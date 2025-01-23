#include<iostream>
#include<string>

using namespace std;

int cnt[130];
int main(){
    string str;
    char output='?';
    int cnt_max=0;
    cin >> str;
    for(int i=0;i<str.length();i++)
    {
        int k=str[i];
        
        if(k>95)k=k-32;
        cnt[k]++;
    }
    for(int i=65;i<=90;i++){
        if(cnt_max<cnt[i]){
            cnt_max=cnt[i];
            output=i;
        }
        else if(cnt_max==cnt[i]){
            output='?';
        }
    }
    cout << output;
}