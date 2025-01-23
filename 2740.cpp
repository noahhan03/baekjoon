#include<iostream>
using namespace std;
int main(){
    int A[101][101],B[101][101];
    int n,m,k;
    int output=0;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>A[i][j];
        }
    }
    cin >> m >> k;
    for(int i=0;i<m;i++){
        for(int j=0;j<k;j++){
            cin >>B[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            output=0;
            for(int k=0;k<m;k++){
                output+=A[i][k]*B[k][j];
            }
            cout <<output<<" ";
        }
        cout <<endl;
    }
}