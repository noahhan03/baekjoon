#include<iostream>

using namespace std;

int basket[101];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    int a,b,num;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> a >> b >> num;
        for (int j=a; j<=b ;j++)
        {
            basket[j]=num;
        }
    }

    //답 출력
    for(int i=1;i<=n;i++){
        cout << basket[i]<<"\n";
    }
}