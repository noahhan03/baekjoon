#include<iostream>

using namespace std;

int map[101][101];
int main()
{
    int n;
    int a,b;
    int cnt=0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a >> b;
        for(int x=a;x<a+10;x++){
            for(int y=b;y<b+10;y++){
                map[x][y]=1;
            }
        }
    }
    for(int i=0;i<=100;i++){
        for(int j=0;j<=100;j++){
            if(map[i][j])cnt++;
        }
    }
    cout << cnt;
}