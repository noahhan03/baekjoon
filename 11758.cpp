#include <iostream>

using namespace std;

int main()
{
    int x1, x2, x3, y1, y2, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    x1 = x2 - x1;
    y1 = y2 - y1;
    x3 = x3 - x2;
    y3 = y3 - y2;
    // p1p2 = (x1, y1) , p2p3=(x3,y3)
    int ccw = x1 * y3 - x3 * y1;
    if (ccw > 0)
        cout << "1\n";
    else if (!ccw)
        cout << "0\n";
    else
        cout << "-1\n";
}