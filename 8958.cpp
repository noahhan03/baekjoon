#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int cnt=0,n,len,row=0;
    char str[81];
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> str;
        len=strlen(str);
        for(int j=0;j<len;j++)
        {
            if(str[j]=='O'){
                row++;
                cnt=cnt+row;
            }
            else row=0;
        }
        cout << cnt <<"\n";
        cnt=0;
    }
}