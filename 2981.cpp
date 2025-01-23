#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int j(int a){
    if(a<0){
        return -a;
    }else{
        return a;
    }
}

int gcd(int a,int b){
    int max=1;
    for(int i=1;i<=a && i<=b;i++){
        if(a%i==0 and b%i==0){
            if(max<i){
                max=i;
            }
        }
    }
    return max;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int arr[110];
    
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    sort(arr,arr+n);

    int v2[110];

    // for(int i=0;i<n-1;i++){
    //     v2[i]= (j(arr[i]-arr[i+1]));
    // }
    
    int k=arr[0];
    for(int i=0;i<(n-1);i++){
        v2[i]=j(arr[i+1]-k);
    }


    int ans=0;
    ans=gcd(v2[0],v2[1]);
    for(int i=0;i<n-1;i++){
        ans=gcd(ans,v2[i]);
    }
    
    for(int i=2;i<=ans;i++){
        if(ans%i==0){
            cout<<i<<" ";
        }
    }
}