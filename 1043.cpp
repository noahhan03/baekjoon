#include<iostream>
#include<vector>
using namespace std;

vector<int> v[52]; //연결되어있는 애들
bool vis[52]; //dfs 의 방문 
int t[52]; //진실을 알고 있는 사람들
vector<int> num_party[52]; //num_party[i] i번째 사람이 참석하는 파티
bool output[52]; //과장해서 말할수 있는 파티 

void dfs(int st){
    if(vis[st])return ;
    vis[st]=1;
    //cout << "st : "<<st << endl;
    //cout <<"num_party[st].size : "<<num_party[st].size()<<endl;
    for(int i=0;i<num_party[st].size();i++){
        //cout << "output 's index : "<<num_party[st][i]<<endl;
        output[num_party[st][i]]=1;
    }
    for(int i=0;i<v[st].size();i++){
        dfs(v[st][i]);
    }
}

int main(){
    int n,m,truth;
    cin >> n >> m; //n : 사람 수 , m: 파티수 
    cin >> truth; //진실 아는 사람 수 
    for(int i=0;i<truth;i++){
        int tt;
        cin >> tt;
        //cout << "tt : "<< tt;
        t[i]=tt;
    }
    for(int i=1;i<=m;i++ ){
        int party;
        cin >> party;
        int z;
        cin >> z;
        num_party[z].push_back(i);
        for(int j=1;j<party;j++){
            int x;
            cin >> x;
            v[z].push_back(x);
            v[x].push_back(z);
            z=x;
            num_party[x].push_back(i);
        }
        
    }
    for(int i=0;i<truth;i++){
        int xx=t[i];
        //cout << "xx : "<<xx <<endl;
        dfs(xx);
    }
    int cnt=0;
    for(int i=1;i<=m;i++){
        if(!output[i])cnt++;
    }
    cout << cnt ;
}