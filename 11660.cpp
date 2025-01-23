#include<iostream>
using namespace std;

int miro[1100][1100];
int sum[1100][1100];
int yy[1100][1100];


int main(){
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> miro[i][j];
        }
    }
    sum[1][1]=miro[1][1];
    for(int i=2;i<=n;i++){
        sum[1][i]=miro[1][i]+sum[1][i-1];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            sum[i][j]=miro[i][j]+sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1];
        }
    }
    cout <<" csu m]\n";
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout <<sum[i][j] <<" ";
        }
        cout << endl;
    }
    for(int i=0;i<m;i++){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout <<"tt:" <<sum[x2][y2]-sum[x1][y1] + miro[x1][y1]<<endl;
    }
}