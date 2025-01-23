#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool vis[1005][1005];

queue<pair<pair<int, int>, int>> q;

int max, day;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int N, M;
vector<vector<int>> box;
bool isValid(int x, int y)
{
    return x >= 0 && y >= 0 && x < N && y < M && box[x][y] == 0 && !vis[x][y];
}
int bfs()
{
    int days = 0;
    while (!q.empty())
    {
        int x = q.front().first.first;  // x
        int y = q.front().first.second; // y
        days = q.front().second;        // cnt
        cout << x << " " << y << " " << days << endl;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (isValid(nx, ny))
            {
                vis[nx][ny] = true;
                box[nx][ny] = 1;
                q.push(make_pair(make_pair(nx, ny), days + 1));
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (box[i][j] == 0)
                return -1;
        }
    }
    return days;
}

int main()
{
    int state;
    cin >> M >> N;
    box.resize(N, vector<int>(M));

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> state;
            box[i][j] = state;
            if (state == 1)
            {
                q.push(make_pair(make_pair(i, j), 0));
                vis[i][j] = true;
            }
        }
    }
    cout << bfs();
}