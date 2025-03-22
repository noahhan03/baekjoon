#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<pair<int, int>> homes;
vector<pair<int, int>> chik;
int ans = 1e9;

int getCity(const vector<int> &pick)
{
    int tot = 0;
    for (auto &h : homes)
    {
        int minD = 1e9;
        for (int idx : pick)
        {
            auto c = chik[idx];
            int curD = abs(c.first - h.first) + abs(c.second - h.second);
            minD = min(curD, minD);
        }
        // cout << "home (" << h.first << "," << h.second << ") dis : " << minD << "\n";
        tot += minD;
    }
    return tot;
}

void back_track(int idx, vector<int> &pick)
{
    if (pick.size() == m)
    {
        ans = min(ans, getCity(pick));
        return;
    }
    for (int i = idx; i < chik.size(); i++)
    {
        pick.push_back(i);
        back_track(i + 1, pick);
        pick.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            if (x == 1)
            {
                homes.push_back({i, j});
            }
            else if (x == 2)
            {
                chik.push_back({i, j});
            }
        }
    }
    vector<int> pick;
    back_track(0, pick);
    cout << ans;
}