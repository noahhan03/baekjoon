#include<iostream>

using namespace std; 

int weight[10001][10001];
int parent[10001];
int depth[10001];


int find(int node)
{
    if(parent[node]==node)return node;
    else return parent[node]=find(parent[node]);
}

bool merge(int x,int y)
{
    int ans_x=find(x);
    int ans_y=find(y);

    if(ans_x==ans_y)return 0;
    else {
        if(depth[x]>depth[y])parent[ans_y]=ans_x;
        else if(depth[x]<depth[y])parent[ans_x]=ans_y;
        else {
            parent[ans_y]=ans_x;
            depth[ans_x]++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int v,e, a,b,c;
    for(int i=0;i<10001;i++)parent[i]=i;
    cin >> v >> e;
    for(int i=0;i<e;i++)
    {
        cin >> a >> b >> c;
        weight[a][b]=c;
        weight[b][a]=c;
    }
}