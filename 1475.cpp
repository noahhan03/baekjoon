#include<iostream>

using namespace std;

int arr[11];

int main()
{
    int n,chk=2,maxx;
    cin >> n;
    while(n && chk){
        int k=n%10;
        arr[k]++;
        n/=10;
        if(n==0)chk--;
    }
    if((arr[6]+arr[9])%2==0)arr[6]=(arr[6]+arr[9])/2 ;
    else arr[6]=(arr[6]+arr[9])/2+1;
    arr[9]=0;
    maxx=arr[0];
    for(int i=1;i<=9;i++)
    {
        if(maxx<arr[i])maxx=arr[i];
    }
    cout << maxx;
}