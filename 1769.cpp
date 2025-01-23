#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

string x;
int sum, cnt;
int main(){
    cin.tie(0);
    cout.tie(0);
    cin >> x;
    while(x.length()!= 1){
        sum = 0;
        for(int i = 0; i < x.length(); i++){
            sum += (x[i] - '0');
        }
        x = to_string(sum);
        cnt++;
    }
    cout << cnt << "\n";
    int chk;
    chk=x[0]-'0';
    if(chk%3==0) cout << "YES";
    else cout << "NO";
    return 0;
}