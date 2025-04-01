#include <iostream>
#include <vector>

using namespace std;

int n;
int arr[100010];
bool vis[100010]; // 방문 확인
bool chk[100010]; // chk 된거
int cnt;

// dfs(4, null) -> dfs(7, 4) -> dfs(6, 4 7) ->
// path : 4 7
// cur : 6
// nxt : 4
void dfs(int cur, vector<int> &path)
{
    vis[cur] = true;
    path.push_back(cur);
    int nxt = arr[cur];
    if (vis[nxt])
    {
        if (chk[nxt] == false)
        {
            bool cyc = false;
            for (int i = 0; i < path.size(); i++)
            {
                int tmp = path[i];
                if (tmp == nxt)
                {
                    cyc = true;
                }
                if (cyc)
                {
                    chk[tmp] = true;
                    cnt++;
                }
            }
        }
    }
    else
    {
        dfs(nxt, path);
    }
}

void test()
{
    cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        vis[i] = false;
        chk[i] = false;
    }
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
        {
            continue;
        }
        vector<int> p;
        dfs(i, p);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        test();
        cout << n - cnt << "\n";
    }
}