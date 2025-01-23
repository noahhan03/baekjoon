#include <iostream>
#include <stack>
#include <string>

using namespace std;

void sol() {
    stack<char> s;
    string ss;
    cin >> ss;
    
    for (int i = 0; i < ss.length(); i++) {
        if (ss[i] == '(') {
            s.push('(');
        } 
        else {
            if (s.empty()) {  
                cout << "NO\n";
                return;
            }
            s.pop();
        }   
    }
    
    if (s.empty()) cout << "YES\n"; 
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        sol();
    }
}
