#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, pair<int, int>> p;

vector<p> edges;
int parent[10001];
int V, E;
int cost;

int find_root(int x)
{
    if (x != parent[x])
    {
        parent[x] = find_root(parent[x]);
    }
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

void init()
{
    sort(edges.begin(), edges.end());
    for (int i = 1; i <= V; i++)
    {
        parent[i] = i;
    }
}

void kru()
{
    int cnt_num = 0;
    for (int i = 0; i < edges.size(); i++)
    {
        int cur_cost = edges[i].first;
        int f = edges[i].second.first;
        int s = edges[i].second.second;
        if (find_root(f) == find_root(s))
        {
            continue;
        }
        union_root(f, s);
        cost += cur_cost;
        cnt_num++;
        if (cnt_num == (V - 1))
        {
            return;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> V >> E;
    for (int i = 0; i < E; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({c, {a, b}});
    }

    init();
    kru();
    cout << cost;
}