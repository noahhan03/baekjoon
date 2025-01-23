#include <iostream>
using namespace std;

int memory[100005];

int main(){
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    int arr=0;
    cin >> arr;
    memory[0]=arr;
    for(int i=1;i<n;i++){
        cin>>arr;
        memory[i+1]=memory[i]+arr;
    }
    for(int i=0;i<m;i++){
        int x,y;
        cin>>y>>x;
        int ans=memory[x]-memory[y-1];
        cout<<ans<<endl;
    } 
    return 0;
}