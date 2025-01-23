#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[10], n, m;
vector<int> o;

// x개의 숫자를 결정했고, y 부터 보자  , 증가용
void f(int x, int y) {
    if (x == m) {
        for (int i = 0; i < m; i++) cout << o[i] << " ";
        cout << "\n";
        return;
    }
    for (int i = y; i < n; i++) { // n 대신 m을 사용하고 있었던 것을 수정했습니다.
        o.push_back(arr[i]);
        f(x + 1, i+1);
        o.pop_back(); // 백트래킹을 위해 마지막 요소를 제거합니다.
        
    }
}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    f(0,0);

    return 0;
}
