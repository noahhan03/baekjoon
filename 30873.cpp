#include<iostream>

using namespace std;

int abss(int a,int b){
    if(a>b)return (a-b);
    else return (b-a);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int x=0;
    int p[200001],c[200001];
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> p[i] >> c[i];
    }
    for(int i=0;i<n;i++){
        if(abss(p[i],x)<=c[i])x++;
    }
    cout << x;
}