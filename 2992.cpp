#include<iostream>

using namespace std;

int arr[10],SizeOfX,x,flag, sol=0;

void BackTrack(int size, int num, int left[]){
    if(size>1 && x<num && !flag){
        flag=1;
        sol=num;
        return ;
    }
    for(int i=0;i<10;i++){
        if(left[i]){
            left[i]--;
            BackTrack(size+1, 10*num+i, left);
            left[i]++;
        }
    }
}


int main()
{   
    int Arrx[10]={0,};
    cin >> x;
    int tempX=x;
    while(tempX>0){
        int temp=tempX%10;
        arr[temp]++;
        Arrx[temp]++;
        tempX/=10;
        SizeOfX++;
    }
    for(int i=1;i<10;i++){
        if(arr[i]){
            arr[i]--;
            BackTrack(1,i,arr);
            arr[i]++;
            if(flag)break;
        }
    }
    cout << sol;
}