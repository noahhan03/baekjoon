#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<pair<int, pair<int, int>>> edges;
int parent[100010];
int cost;
int cutMAX = -1;

int find_root(int x)
{
    if (x != parent[x])
        parent[x] = find_root(parent[x]);
    return parent[x];
}

void union_root(int x, int y)
{
    x = find_root(x);
    y = find_root(y);
    if (x != y)
    {
        if (x > y)
            parent[y] = x;
        else
            parent[x] = y;
    }
}

void kru()
{
    int mst_cnt = 0;
    for (int i = 0; i < edges.size(); i++)
    {
        int f = edges[i].second.first;
        int s = edges[i].second.second;
        int cur_cost = edges[i].first;

        if (find_root(f) == find_root(s))
            continue;

        cost += cur_cost;
        if (cutMAX < cur_cost)
            cutMAX = cur_cost;

        union_root(f, s);
        mst_cnt++;

        if (mst_cnt == N - 1)
            return;
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({c, {a, b}});
    }
    for (int i = 1; i <= N; i++)
        parent[i] = i;

    sort(edges.begin(), edges.end());
    kru();

    cout << cost - cutMAX;
}