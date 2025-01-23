#include <iostream>
#include <queue>

using namespace std;

char map[110][110];
bool vis[110][110];
int cnt;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n, m;

int bfs(int x, int y)
{
    queue<pair<int, pair<int, int>>> q;
    q.emplace(x, y, 0);
    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second.first;
        int current_cnt = q.front().second.second;
        vis[cx][cy] = true;
        q.pop();
        if (cx == n && cy == m)
        {
            // cout<<xx<<" "<<yy<<"\n";
            return current_cnt;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || vis[nx][ny] == true)
                continue;
            else if (vis[nx][ny] == false)
            {
                q.emplace(nx, ny, current_cnt);
                current_cnt++;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    // 데이터 입력 받기
    for (int i = 0; i < n; ++i)
    {
        string row;
        cin >> row; // 문자열로 입력받기
        for (int j = 0; j < m; ++j)
        {
            map[i][j] = row[j] - '0'; // 문자 '0'을 빼서 정수로 변환
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
    cout << bfs(0, 0);
}