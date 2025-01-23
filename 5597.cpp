#include<iostream>
using namespace std;

int chk[31][1];

int main()
{
    int k;
    for(int i=0;i<28;i++)
    {
        cin >> k;
        chk[k][0]++;
    }
    for (int i=1;i<=30;i++){
        if(!chk[i][0]){
            cout << i << "\n";
        }
    }
}