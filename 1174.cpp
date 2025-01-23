#include<iostream>

#define ll long long 
#define INF 9876543210 // 제일 큰수도 10자리 

using namespace std;
int n;
int cnt ;  // 줄어드는 수 몇 번째인지 카운트 , n==cnt 이면 현재 줄어드는 수 출력 
ll res=-1; // output

// size - n 자리수  cur, 현재 보고 있는 수 
void BT(int size, ll cur){
    if(!size){
        cnt ++ ;
        if(cnt==n ){
            res=cur;
        }
        return ;
    }
    
    int temp = cur%10;
    if(!cur)temp=10; 
    for(int i=0;i<temp;i++){
        ll nxt=cur*10 +i;
        if(i==0 && cur==0)continue;
        BT(size-1, nxt);
    }
    
}



int main(){
    cin >> n; 
    for(int i=0;i<=10;i++){
        //biggest num for declining num is 10 degit . INF 
        BT(i,0);
    }
    cout << res;
}