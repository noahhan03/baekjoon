#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    long long n;
    cin >> n;

    long long test = 0; // 디버그 모드 제어
    auto compare = [](const pair<long long, long long> &a, const pair<long long, long long> &b)
    {
        return a.second > b.second; // second 기준 오름차순
    };

    // 입력용 우선순위 큐 (first 기준 오름차순)
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;

    // 우선순위 큐 대체용 v (second 기준 오름차순)
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, decltype(compare)> pq_box(compare);

    // 입력 처리
    for (long long i = 0; i < n; i++)
    {
        long long s, t;
        cin >> s >> t;
        pq.emplace(s, t);
    }

    // 첫 번째 요소를 pq_box에 삽입
    long long setX = pq.top().first;
    long long setY = pq.top().second;
    pq.pop();
    pq_box.emplace(setX, setY);

    // 나머지 처리
    while (!pq.empty())
    {
        long long cx = pq.top().first;
        long long cy = pq.top().second;
        pq.pop();

        // 기존 요소들과 비교
        long long checkX = pq_box.top().first;
        long long checkY = pq_box.top().second;
        if (checkY <= cx)
        {
            pq_box.pop(); // 기존 요소 갱신
            pq_box.emplace(checkX, cy);
        }
        else
        {
            // 새로운 요소 추가
            pq_box.emplace(cx, cy);
        }
    }

    cout << pq_box.size(); // 결과 크기 출력
    return 0;
}
