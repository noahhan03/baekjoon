#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;

int LIS(vector<int> &a)
{
    vector<int> lis;
    for (int x : a)
    {
        auto it = lower_bound(lis.begin(), lis.end(), x);
        if (it == lis.end())
        {
            lis.push_back(x);
        }
        else
        {
            *it = x;
        }
    }
    return lis.size();
}

int main()
{
    vector<int> A;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        A.push_back(a);
    }
    cout << LIS(A) << "\n";
}