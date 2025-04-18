#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;
int n, w[16][16];
int dp[16][1 << 16];

int tsp(int curr, int visited)
{
    if (visited == (1 << n) - 1)
    {
        return w[curr][0] ? w[curr][0] : INF; // Return to starting point
    }
    if (dp[curr][visited] != -1)
    {
        return dp[curr][visited];
    }
    int &res = dp[curr][visited] = INF;
    for (int nxt = 0; nxt < n; nxt++)
    {
        // w[curr][nxt] : curr에서 nxt로 가는 비용, 0이면 갈 수 없음
        // visited&(1<<nxt) : nxt가 방문했는지 확인
        if (!(visited & (1 << nxt)) && w[curr][nxt])
        {
            res = min(res, tsp(nxt, visited | (1 << nxt)) + w[curr][nxt]);
        }
    }
    return res;
    // dp[curr][visited] = res;
}

int main()
{
    cin >> n;
    // n <= 16
    // 1 <= w[i][j] <= 1,000,000
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> w[i][j];
        }
    }
    fill(&dp[0][0], &dp[15][(1 << 16) - 1] + 1, -1);
    cout << tsp(0, 1) << "\n";
    return 0;
}