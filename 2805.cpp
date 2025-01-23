#include<iostream>
#include<algorithm>

using namespace std;

#define int long long 

long long arr[1000001];
long long maxx;

long long remain(long long h,long long n)
{
    long long cnt=0;
    for(long long i=0;i<n;i++)
    {
        if(arr[i]>=h)cnt=cnt+arr[i]-h;
    }
    return cnt;
}

long long bin(long long x, long long n)
{
    long long st=0;
    long long en=maxx-1;
    long long k;
    while(st<=en){
        long long mid=st+(en-st)/2;
        if(x<remain(mid,n)){
            st=mid+1;
            k=mid;
        }
        else if(x>remain(mid,n)){
            en=mid-1;
        }
        else return mid;
    }
    return k;
}

main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n,m,h,k;
    cin >> n >> m ;
    cin >> arr[0];
    maxx=arr[0];
    for(long long i=1;i<n;i++){
        cin >> arr[i];
        if(maxx<arr[i])maxx=arr[i];
    }
    cout << bin(m,n);
}