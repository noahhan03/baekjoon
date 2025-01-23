#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int alp[26];


bool Comp(string a, string b) {
        if (a.length() != b.length()) {
            return a.length() > b.length();
        }
        else {
            return a > b;
        }
}

bool desc(int a, int b){ return a > b; }

int main(){
    int n,output=0;
    vector<string> v;
    cin >> n;
    for(int i=0;i<n;i++){
            string word;
            cin >> word;
            v.push_back(word);
    }
        // sort(v.begin(),v.end(),Comp);
    for(int i=0;i<n;i++){
        int calck=1;
        for(int j=v[i].size()-1;j>=0;j--){
                int k=v[i][j]-'A';
                alp[k]+=calck;
                calck*=10;
        }
    }
    sort(alp,alp+26,desc);
    for(int i=0;i<10;i++){
            output+=alp[i]*(9-i);
    }
    cout << output;
}