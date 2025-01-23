#include<iostream>
using namespace std;


int arr[1000001];

int main(){
    int m,n;
    arr[0]=1;
    arr[1]=1;
    cin >> m >> n;
    for(int i=2;i<=n;i++){
        for(int j=2*i;j<=n;j+=i){
            if(!arr[j])arr[j]=1;//0이면 소수 ,나눠지면 소수 아님,
        } 
    }
    for(int i=m;i<=n;i++)if(!arr[i])cout<<i<<endl;
}