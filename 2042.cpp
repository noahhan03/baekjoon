#include<iostream>

typedef long long ll;

using namespace std;


ll Tree[3000001];

void update(int node, int start, int end, int index, ll value) {
    if (index < start || end < index) return;
    else if (start == end) Tree[node] = value;
    else {
        ll mid = (start + end) / 2;
        update(node * 2, start, mid, index, value);
        update(node * 2 + 1, mid + 1, end, index, value);
        Tree[node] = Tree[node * 2] + Tree[node * 2 + 1];
    }
}


ll query(ll node, ll st, ll en, ll l , ll r ){
    if(st > r || en < l)return 0;
    else if(l <= st && en <=r)return Tree[node];
    else {
        int mid= (st+en)/2;
        return query(node * 2, st, mid, l, r) +query(node * 2 + 1, mid + 1, en, l, r);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,m, k; //M은 수의 변경이 일어나는 횟수이고, K는 구간의 합을 구하는 횟수
    int cmd;
    ll b,c,a,index,change;
    cin >> n >> m >> k;
    for(ll i=1;i<=n;i++)
    {
        cin >> a;
        update(1,1,n,i,a);
    }
    for(ll i=0;i<m+k;i++)
    {
        cin >> cmd; //cmd-a 
        cin >> b >> c;
        if(cmd==1){ // b(1 ≤ b ≤ N)번째 수를 c로 바꾸고
            change=c-Tree[b];
            index=b;
            update(1,1,n,b,c);
        }
        else if(cmd==2) { //b(1 ≤ b ≤ N)번째 수부터 c(b ≤ c ≤ N)번째 수까지의 합
            cout << query(1,1,n,b,c) << endl;
        }
    }
}