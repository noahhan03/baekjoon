#include<iostream>
using namespace std;

int arr[12345678];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int a;
        cin >> a; 
        arr[a]++;
    }
    int cnt=0;
    int result=0;
    int temp1,temp2;
    for(int i=1;i<=12345678;i++){
        while(arr[i]){
            arr[i]--;
            cnt++;
            if(cnt==1){
                temp1=i;
            }
            if(cnt==2){
                cnt=0;
                temp2=i;
                int temp=temp1+temp2;
                arr[temp]++;
                result+=temp;
            }
        }
    }
    cout << result ;
}