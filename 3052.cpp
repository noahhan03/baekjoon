#include <iostream>
using namespace std;

int count[42];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int k,ans=0;
    for(int i=0;i<10;i++){
        cin >> k;
        k=k%42;
        count[k]++;
        if(count[k]==1)ans++;
    }
    cout << ans;
}