#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> adj[20005];
int dis[20005]; // st 에서 [i]까지 가는데 최소 비용
int V, E, K;
bool vis[20005];

void dij(int st)
{
    fill(dis, dis + V + 1, 2147483646);
    dis[st] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(dis[st], st));
    while (!pq.empty())
    {
        int d = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if (vis[cur])
            continue;
        if (dis[cur] < d)
            continue;
        vis[cur] = 1;
        for (int i = 0; i < adj[cur].size(); i++)
        {
            int nxt = adj[cur][i].first;
            int nxt_dis = adj[cur][i].second + d; // 현재 st -> nxt 가는 비용
            if (nxt_dis < dis[nxt])
            {
                dis[nxt] = nxt_dis;
                pq.push(make_pair(nxt_dis, nxt));
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> V >> E >> K; // k는 시작 정점 번호
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    dij(K);
    for (int i = 1; i <= V; i++)
    {
        if (dis[i] == 2147483646)
            cout << "INF\n";
        else
            cout << dis[i] << "\n";
    }
}