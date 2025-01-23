#include<iostream>

using namespace std;

int n,s;
int arr[52];


void print_arr(){
    for(int i=0;i<n;i++){
        cout << arr[i]<<" ";
    }
    cout << "\n";
}

int main(){
    int curmax=0;
    int maxidx=0;
    int req_idx=0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cin >> s;
    for(int i=0;i<n;i++){
        curmax=arr[i];
        maxidx=i;
        for(int j=i+1;j<i+s+1 && j<n;j++){
            if(curmax<arr[j]){
                curmax=arr[j];
                maxidx=j;
            }
        }
        for(int j=maxidx;j>i;j--)arr[j]=arr[j-1];
        arr[i]=curmax;
        s-=maxidx;
        s+=i;
    }
    for(int i=0;i<n;i++){
        cout << arr[i]<<" ";
    }
}