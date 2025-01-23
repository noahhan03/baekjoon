#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> chocolates(N);

    for(int i = 0; i < N; i++) {
        cin >> chocolates[i];
    }

    int newBoxes = 0;
    for(int i = 1; i < N; i++) {
        if(chocolates[i] > chocolates[i - 1]) {
            newBoxes++;
        }
    }

    cout << newBoxes << endl;
    return 0;
}
