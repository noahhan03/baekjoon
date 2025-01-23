#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int n,cnt;
bool pass[250001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
	cin >> n;

	for (int i = 1; i <= 500; i++) {
		pass[i*i] = true;
	}
	
	for (int i = 1; i <= 500; i++) {
		if (i*i - n > 0 && pass[i*i - n] == true) cnt++;
	}

	cout << cnt ;
	return 0;
}