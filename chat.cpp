#include <iostream>
#include <vector>
#include <algorithm>
#include<cstring>

using namespace std;

int n;
int board[11][11];
bool visited[11][11];
int max_bishops = 0;

// 대각선 이동 방향 (좌상-우하, 우상-좌하)
int delx[4] = {-1, 1, 1, -1};
int dely[4] = {-1, 1, -1, 1};

void dfs(int idx, int cnt) {
    if (idx == n * n) {
        max_bishops = max(max_bishops, cnt);
        return;
    }

    int x = idx / n;
    int y = idx % n;

    if (board[x][y] && !visited[x][y]) {
        // 현재 위치에 비숍을 놓는다.
        bool temp_vis[11][11];
        memcpy(temp_vis, visited, sizeof(visited));

        visited[x][y] = true;

        // 대각선 방향을 모두 막는다.
        for (int i = 0; i < 4; i++) {
            int nx = x + delx[i];
            int ny = y + dely[i];
            while (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                temp_vis[nx][ny] = true;
                nx += delx[i];
                ny += dely[i];
            }
        }

        // 다음 위치 탐색
        dfs(idx + 1, cnt + 1);

        // 현재 위치에 비숍을 놓지 않고 다음 위치 탐색
        memcpy(visited, temp_vis, sizeof(visited));
    }

    // 현재 위치에 비숍을 놓지 않고 다음 위치 탐색
    dfs(idx + 1, cnt);
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    dfs(0, 0);
    cout << max_bishops << endl;

    return 0;
}
