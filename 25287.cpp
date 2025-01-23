#include<iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t,n,c,chk=0;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        cin >> n;
        for(int j=0;j<n;j++){
            cin >> c;
            if(c!=(j+1) && c!=(n-j+2) && c!=(j+2) && c!=(n-j+3)){
                chk=1;
            }
        }
        if(chk){
            cout <<"NO\n";
            chk=0;
        }
        else {
            cout <<"YES\n";
        }
    }
}