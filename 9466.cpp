#include <iostream>
#include <stack>

using namespace std;

void test()
{
    int n, res = 0, check_num = 0;

    cin >> n;

    int arr[n + 2];
    bool check[n + 2] = {
        false,
    };

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        if (arr[i] == i)
        {

            check[i] = true;
            check_num++;
        }
        else
            check[i] = false;
    }

    for (int i = 1; i <= n; i++)
    {
        if (check_num == n)
            break;

        int st = i;
        stack<int> qq;
        qq.push(i);
        while (!qq.empty())
        {
            int cur = qq.top();

            if (check[arr[cur]] == true)
            {
                while (!qq.empty())
                {
                    int check_idx = qq.top();
                    qq.pop();
                    check[check_idx] = true;
                    res++;
                    check_num++;
                }
            }
            if (arr[cur] == i)
            {
                while (!qq.empty())
                {
                    int check_idx = qq.top();
                    qq.pop();
                    check[check_idx] = true;
                    check_num++;
                }
            }
            else if (check[arr[cur]] == false)
            {
                qq.push(arr[cur]);
            }
        }
    }

    cout << res << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        test();
    }
}