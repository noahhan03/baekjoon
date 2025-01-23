#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<char> v;
vector<char> pass;
int l,c;

void M_P(int st, int cnt){
    //pcout
    if(cnt==l){
        int vow=0;
        int con=0;
        for(int i=0;i<pass.size();i++){
            if (pass[i] == 'a' || pass[i] == 'e' || pass[i] == 'i' || pass[i] == 'o' || pass[i] == 'u')
                vow++;
            else
                con++;
        }
        if(vow>=1 && con>=2){
            for(int i=0;i<pass.size();i++){
                cout<<pass[i];
            }
            cout<<"\n";
        }
        return ;
    }

    for(int i=st;i<v.size();i++){
        pass.push_back(v[i]);
        M_P(i+1,cnt+1);
        pass.pop_back();
    }
    return;
}

int main(){
    cin >> l >> c;
    for(int i=0;i<c;i++){
        char chr;
        cin >> chr;
        v.push_back(chr);
    }
    sort(v.begin(),v.end());
    M_P(0,0);
}