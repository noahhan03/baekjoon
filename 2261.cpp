#include<iostream>

using namespace std;

int square(int a){return a*a;}
int mmm(int a,int b){
    return a>b?b:a;
}
int abs(int a,int b){
    a=a-b;
    if(a>0)return a;
    else return -a;
}

int arr[100010][2];

int main(){
    int min=2e9;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        arr[i][0]=a;arr[i][1]=b;
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int d1,d2;
            d1=abs(arr[i][0],arr[j][0]);
            d2=abs(arr[i][1],arr[j][1]);
            d1=square(d1);d2=square(d2);
            min=mmm(min,d1+d2);
        }
    }
    cout << min;
}