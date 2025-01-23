#include<iostream>

using namespace std;

int main()
{
    char str[52], bb[3];
    int z;
    float add=0,res=0,k,avg=0;
    float a,b;
    for(int i=0;i<20;i++)
    {
        cin >> str >> a>>bb;
        k=0;
        if(bb[0]!='P' &&bb[0]!='F'){
            
            z=69-bb[0];
            cout << z <<endl;
            k=(float)z;
            if(bb[1]=='+')k+=0.5;
            res+=k*a;
            avg+=a;
        }
        else if(bb[0]=='F'){
            avg+=0;
            res+=0;
        }
    }
    if(avg==0)cout << "0";
    else    cout << res/avg;
}