#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
char map[1010][1010];
bool vis[1010][1010];
queue<pair<int, int>> q;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs()
{
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || map[nx][ny] == '1' || vis[nx][ny] == true)
                continue;
            vis[nx][ny] = true;
            map[nx][ny] = '2';
            q.push({nx, ny});
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            if (i == 0 && map[i][j] == '0')
            {
                q.push({i, j});
                vis[i][j] = true;
                map[i][j] = '2';
            }
        }
    }
    bfs();
    bool flag = 0;

    for (int j = 0; j < m; j++)
    {
        if (map[n - 1][j] == '2')
        {
            flag = 1;
            break;
        }
    }

    if (flag)
    {
        cout << "YES";
    }
    else
        cout << "NO";
}