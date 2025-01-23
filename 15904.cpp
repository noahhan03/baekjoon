#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    char str[1001];
    char out[4]={'U','C','P','C'};
    int cnt=0,chk=1;
    cin.getline(str,1001,'\n');
    for(int i=0;i<strlen(str);i++){
        if(out[cnt]==str[i]){
            cnt++;
        }
        if(cnt==4)break;
    }
    if(cnt==4)cout <<"I love UCPC";
    else 
        cout << "I hate UCPC";
}