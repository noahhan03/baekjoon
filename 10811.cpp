#include<iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,a,b,arr[103];
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        arr[i]=i;
    }
    for(int i=0;i<m;i++)
    {
        cin >> a >> b;
        while(a<=b){
            int temp=arr[a];
            arr[a]=arr[b];
            arr[b]=temp;
            a++;
            b--;
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout <<arr[i] <<' ';
    }
}