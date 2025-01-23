#include<iostream>
#include<algorithm>

using namespace std;

int walk;
int book_m[53];
int cnt_m;
int book_p[53];
int cnt_p;

int main()
{
    ios::sync_with_stdio(0);    
    cin.tie(0);
    int n,m;
    int pp,mm;
    int book;
    cin >> n >> m;  
    for(int i=0;i<n;i++){
        cin >> book;
        if(book>0)book_p[cnt_p++]=book;
        else book_m[cnt_m++]=book;
    }
    sort(book_p,book_p+cnt_p);
    sort(book_m,book_m+cnt_m,greater<>());
    //for(int i=0;i<cnt_m;i++)cout << book_m[i] <<"\n";
    for(int i=0;i<n;i+=m){
        pp=book_p[cnt_p-1];
        mm=-book_m[cnt_m-1];
        cout << "pp : "<<pp<<"mm : "<< mm <<"\n";
        if(pp>mm ){
            walk+=2*pp;
            if(cnt_p>=m)cnt_p-=m;
            else cnt_p=0;
        }
        else if(pp<mm){
            walk+=2*mm;
            if(cnt_m>=m)cnt_m-=m;
            else cnt_m=0;
        }
    }
    cout << walk;
}