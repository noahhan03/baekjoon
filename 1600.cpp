#include <iostream>
#include <queue>
#include <tuple>
#include <climits>

using namespace std;

int k, w, h, map[210][210];
bool vis[210][210][31]; // Third dimension for remaining horse moves
int dx[12] = {1, -1, 0, 0, -1, 1, -2, 2, -2, 2, -1, 1};
int dy[12] = {0, 0, 1, -1, -2, -2, -1, -1, 1, 1, 2, 2};

int bfs()
{
    queue<tuple<int, int, int, int>> q; // (x, y, remaining k, move count)
    q.emplace(0, 0, k, 0);
    vis[0][0][k] = true;

    while (!q.empty())
    {
        auto [x, y, cur_k, cur_cnt] = q.front();
        q.pop();

        if (x == h - 1 && y == w - 1)
        {
            return cur_cnt; // Reached destination
        }

        for (int i = 0; i < 12; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nk = cur_k;

            // Check if the move is valid
            if (nx < 0 || ny < 0 || nx >= h || ny >= w || map[nx][ny] == 1)
                continue;

            // Handle horse moves
            if (i > 3)
            {
                if (nk == 0)
                    continue; // No horse moves left
                nk--;         // Use a horse move
            }

            if (!vis[nx][ny][nk])
            {
                vis[nx][ny][nk] = true;
                q.emplace(nx, ny, nk, cur_cnt + 1);
            }
        }
    }
    return -1; // Destination not reachable
}

void solve()
{
    cin >> k >> w >> h;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> map[i][j];
        }
    }
    cout << bfs() << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
