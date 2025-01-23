#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int cmp(string a, string b) {
	// 1. 길이가 같다면, 사전순으로
	if (a.length() == b.length()) {
		return a < b;
	}
	// 2. 길이가 다르다면, 짧은 순으로 
	else {
		return a.length() < b.length();
	}
}

int main(){
    int n;
    vector<string> s;
    string in;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> in ;
        s.push_back(in);
    }
    sort(s.begin(),s.end(),cmp);    
    for(int i=0;i<n;i++){
        if(s[i]==s[i-1])continue;
        cout<<s[i]<<endl;
    }
}