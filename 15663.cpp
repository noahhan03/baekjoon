#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[10], n, m;

// x개의 숫자를 결정했고
void f(int x, vector<int>& o) {
    if (x == m) {
        for (int i = 0; i < m; i++) cout << o[i] << " ";
        cout << "\n";
        return;
    }
    for (int i = 0; i < n; i++) { // n 대신 m을 사용하고 있었던 것을 수정했습니다.
        if (find(o.begin(), o.end(), arr[i]) == o.end()) { // 중복된 값을 방지합니다.
            o.push_back(arr[i]);
            f(x + 1, o);
            o.pop_back(); // 백트래킹을 위해 마지막 요소를 제거합니다.
        }
    }
}

void nm() {
    for (int i = 0; i < n; i++) { // n개의 숫자를 처리해야 하므로 n으로 수정
        vector<int> ttt;
        ttt.push_back(arr[i]);
        f(1, ttt);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    vector<int> vec;
    for(int i=0;i<n;i++){
        int xxx;
        cin >> xxx;
        vec.push_back(xxx);
    }
    sort(vec.begin(),vec.end());
    vec.erase(unique(vec.begin(),vec.end()), vec.end());
    n=vec.size();
    for(int i=0;i<n;i++){
        arr[i]=vec[i];
    }
    sort(arr, arr + n);
    nm();

    return 0;
}
