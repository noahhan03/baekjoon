#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <long long int> v;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    
    for(int i=0;i<n;i++){
        long long int tmp;
        cin>>tmp;
        
        v.push_back(tmp);
    }
    
    reverse(v.begin(),v.end());
    
    long long int cnt=0;
    long long int pre=0;
    for(int i=0;i<n;i++){
        if(pre+1<v[i]){
            v[i]=pre+1;
            pre=v[i];
        }else{
            pre=v[i];
        }
    }
    
    for(int i=0;i<n;i++){
        cnt+=v[i];
    }
    
    cout<<cnt;
        
    return 0;
}