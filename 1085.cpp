#include<iostream>
using namespace std;
int abs(int a, int b){
    return a>b ? a-b : b-a;
}
int main()
{
    int x,y,w,h;
    cin >> x>> y >> w >> h;
    if(abs(x,w)>=abs(y,h)){
        if(x>=abs(y,h)){
            if(y>=abs(y,h))cout << abs(y,h); 
            else cout << y;
        }
        else {
            if(x>=y)cout << y;
            else {
                cout << x;
            }
        }
    }
    else if(x>=abs(x,w)){
        if(abs(x,w)>=y)cout << y;
        else cout << abs(x,w);
    }
}


