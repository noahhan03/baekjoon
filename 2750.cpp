#include<iostream>
#include<cstdlib>

using namespace std;

int arr[1001]={0,};


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin >> n;
    
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                k=arr[i];
                arr[i]=arr[j];
                arr[j]=k;
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        cout << arr[i]<<"\n";
    }

}