#include<iostream>
#include<string>
#include<vector>
#include<utility>

using namespace std;


vector<pair<vector<char>,int>> sentence;



int cnt; // 학습 가능한 단어 개수  
int n,k; // n단어 개수 k 학습 알파벳 남은 개수 
void rearrange(string str){
    string temp;
    vector<char> ned ;
    int CntOfStr=0;
    for(int i=0;i<str.size();i++){
        if(str[i]=='a' || str[i]=='n' || str[i]=='t' || str[i]=='i' || str[i]=='c')continue;
        else {
            ned.push_back(str[i]);
            CntOfStr++;
        }
    }
    if(CntOfStr<=k){
        sentence.push_back(make_pair(ned,CntOfStr));
        cnt++;
    }
}

int main(){
    string str;
    cin >> n >> k;
    k-=5; // k는 새로 가르칠 수 있는 단어 
    for(int i=0;i<n;i++){
        cin >> str;
        rearrange(str);
    }
    for(const auto& pair : sentence){
        cout << "sentences : ";
        for(char alpha : pair.first){
            cout << alpha<<" ";
        }
        cout << "cnt : " << pair.second <<"\n";
    }
}