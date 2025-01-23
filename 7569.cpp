#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int map[101][101][101];
int m, n, h;
queue<pair<pair<int, int>, int>> q;
bool vis[101][101][101];
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int bfs()
{
    int date = 0;

    while (!q.empty())
    {
        int size = q.size();
        for (int j = 0; j < size; j++)
        {
            int z = q.front().first.first;
            int x = q.front().first.second;
            int y = q.front().second;
            q.pop();

            for (int i = 0; i < 6; i++)
            {
                int nz = z + dz[i];
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nz < 0 || nz >= h || nx < 0 || nx >= n || ny < 0 || ny >= m || map[nz][nx][ny] == -1 || vis[nz][nx][ny])
                    continue;

                vis[nz][nx][ny] = true;
                map[nz][nx][ny] = 1;
                q.push({{nz, nx}, ny});
            }
        }
        if (!q.empty())
            date++;
    }

    return date;
}

int main()
{
    cin >> m >> n >> h;

    for (int k = 0; k < h; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> map[k][i][j];
                if (map[k][i][j] == 1)
                {
                    q.push({{k, i}, j});
                    vis[k][i][j] = true;
                }
            }
        }
    }

    int res = bfs();

    for (int k = 0; k < h; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (map[k][i][j] == 0)
                {
                    cout << -1 << '\n';
                    return 0;
                }
            }
        }
    }

    cout << res << '\n';
    return 0;
}
