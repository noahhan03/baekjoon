#include<iostream>
using namespace std;

double arr[10001];

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.precision(3);
    cout << fixed;
    int n;
    double ans;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    ans=arr[1];
    for(int i=1;i<=n;i++){
        double comp=1;
        for(int j=i;j<=n;j++){
            comp*=arr[j];
            ans=max(comp,ans);
        }
    }
    cout << ans;
}