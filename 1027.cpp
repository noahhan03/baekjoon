#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <string>
using namespace std;

double a, b;

void g(int x1, int y1, int x2, int y2){
    a = double(y2 - y1) / double(x2 - x1);
    b = y1 - (a * x1); 
    return;
}

int main() {
    int n;
    int arr[51] = {0};
    int cnt[51] = {0};
    scanf("%d", &n);
    for(int i = 1; i < n + 1; i ++){
        scanf("%d", &arr[i]);
    }

    for(int i = 1; i < n + 1; i++){
        for(int k = i + 1; k < n + 1; k++){
            g(i, arr[i], k, arr[k]);
            int f = 0;
            for(int q = i + 1; q < k; q++){
                if((double)arr[q] >= (a * q) + b){
                    f = 1;
                    break;
                }
            }
            if(f == 0){
                cnt[i]++;
                cnt[k]++;
            }
        }
    }

    int m = 0;
    for(int i = 1; i <= n; i ++){
        m = m > cnt[i] ? m : cnt[i];
    }

    printf("%d", m);
    return 0;
}