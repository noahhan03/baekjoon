    #include<iostream>
    #include<algorithm>

    using namespace std;

    int map[501][501];
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    int n,m;
    int max1;

    void dfs(int x,int y){
        map[x][y]=0;
        for(int i=0;i<4;i++)
        {
            int nx= x +dx[i];
            int ny= y +dy[i];   
            if(nx<0 || ny <0 || n <=nx || m<=ny)continue;
            if(map[nx][ny]==1){
                map[nx][ny]=0;
                max1++;
                dfs(nx,ny);
            }
        }
    }

    int main()
    {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int cnt=0;
        vector<int> vec;
        cin >> n >> m;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++){
                cin >> map[i][j];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(map[i][j]==1){
                    cnt++;
                    dfs(i,j); 
                    vec.push_back(max1);
                    max1=1;
                }
            }
        }

        if(cnt){
            cout << cnt <<"\n"<< *max_element(vec.begin(),vec.end());
        }
        else {
            cout << cnt << "\n"<<"0"; 
        }
    }