#include<iostream>
#include<string>
using namespace std;



int main(){
    string a,b;
    cin >> a >> b;
    int calc , lena , lenb ,diff=0,cnt;
    lena = a.length();
    lenb = b.length();
    calc = lenb - lena; // calc==0 이면 연산 할 이유가 없다. 
    if(calc==0){
        for(int i=0;i<lenb;i++){
            if(a[i]!=b[i])diff++;
        }
    }
    else {
        diff=53;
        for(int i=0;i<=calc;i++){
            int cnt=0;
            for(int j=0;j<lena;j++){
                if(a[j]!=b[i+j])cnt++;
            }
            if(diff>cnt)diff=cnt;
        }
    }
    cout << diff;
}