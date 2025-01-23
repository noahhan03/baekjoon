#include<iostream>
using namespace std;
int main(){
    int arr[5];
    int avg=0;
    for(int i=0;i<5;i++){
        cin >> arr[i];
        avg+=arr[i];
    }
    for(int i=0;i<5;i++){
        for(int j=i+1;j<5;j++){
            if(arr[i]>arr[j]){
                int t=arr[i];
                arr[i]=arr[j];
                arr[j]=t;
            }
        }
    }
    cout << avg/5<< endl;
    cout << arr[2];
}