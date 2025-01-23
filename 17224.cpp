#include<iostream>  

using namespace std;

int cc[101];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,l,k,point=0,chk=1;
    int a[101],b[101];
    cin >> n >> l >> k; //n 문제 개수, l 역량(최대 난도), k 문제 풀수잇는 개수 
    for(int i=0;i<n;i++)
    {
        cin >> a[i] >> b[i];
    }
    for(int i=0;i<n;i++)
    {
        if(k==0){
            chk=0;
            break;
        }
        if(b[i]<= l){
            cc[i]=1;
            point=point+140;
            k--;
        }
        
    }
    if(chk){
        for(int i=0;i<n;i++){
            if(k==0){
                break;
            }
            if(a[i]<=l && cc[i]!=1){
                point=point+100;
                k--;
            }
      
        }
    }
    cout << point;
}