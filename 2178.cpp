#include <iostream>
#include <queue>

using namespace std;

char miro[110][110];

bool vis[110][110];
int n, m;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void printmap(int x, int y)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (i == x && j == y)
            {
                cout << '2';
            }
            cout << miro[i][j];
        }
        cout << "\n";
    }
}

int bfs(int x, int y)
{
    queue<pair<int, pair<int, int>>> q;
    q.push(make_pair(x, make_pair(y, 1)));
    vis[x][y] = 1;
    while (!q.empty())
    {
        int xx = q.front().first;
        int yy = q.front().second.first;
        int dids = q.front().second.second; // cnt
        q.pop();
        vis[xx][yy] = 1;
        if (xx == n && yy == m)
        {
            // cout<<xx<<" "<<yy<<"\n";
            return dids;
        }
        for (int i = 0; i < 4; i++)
        {
            int xxx = xx + dx[i];
            int yyy = yy + dy[i];

            if (xxx <= 0 || xxx > n || yyy <= 0 || yyy > m || vis[xxx][yyy] || miro[xxx][yyy] == '0')
                continue;
            cout << "x : " << xxx << " y : " << yyy << " cnt : " << dids << "\n";
            printmap(xxx, yyy);
            q.push(make_pair(xxx, make_pair(yyy, dids + 1)));
            vis[xxx][yyy] = 1; // gray 같은 거 생각
        }
    }
    return -1;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> miro[i][j];
        }
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= m; j++)
    //     {
    //         cout << miro[i][j];
    //     }
    // }
    cout << bfs(1, 1);
}