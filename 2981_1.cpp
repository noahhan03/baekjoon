#include <iostream>
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
    int n;
    vector <int> v;
    cin>>n;
    
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    v=sor
    vector <int> v2;
    for(int i=0;i<n-1;i++){
        v2.push_back(j(v[i]-v[i+1]));
    }
    
    int ans=0;
    ans=gcd(v2[0],v2[1]);
    for(int i=0;i<v.size()-1;i++){
        ans=gcd(ans,v2[i]);
    }
    
    for(int i=2;i<=ans;i++){
        if(ans%i==0){
            cout<<i<<" ";
        }
    }
    return 0;
}