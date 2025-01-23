#include<iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int map[20][20];
    int chk=1,b=0,w=0;
    for(int i=0;i<19;i++)
    {
        for(int j=0;j<19;j++)
        {
            cin >> map[i][j];
            if(map[i][j]==1)b++;
            if(map[i][j]==2)w++;
        }
    }
    if(b>w+1 || b<w-1){
        chk=0;
        cout <<"0\n";
    }
    for(int i=0;i<19;i++)
    {
        for(int j=0;j<19;j++)
        {
            if(map[i][j]==1 && chk){
                if(map[i+1][j]==1 && map[i+2][j]==1 && map[i+3][j]==1 && map[i+4][j]==1){
                    cout << "1\n";
                    cout << i+1 <<" " << j+1;
                    chk=0;
                    break;
                }
                else if(map[i][j+1]==1 && map[i][j+2]==1 && map[i][j+3]==1 && map[i][j+4]==1){
                    cout <<"1\n";
                    cout << i+1 <<" "<<j+1;
                    chk=0;
                    break;
                }
                else if(map[i+1][j+1]==1 &&map[i+2][j+2]==1 &&map[i+3][j+3]==1 &&map[i+4][j+4]==1){
                    cout <<"1\n";
                    cout << i+1 <<" "<<j+1;
                    chk=0;
                    break;
                }
                else if(map[i-1][j-1]==1 &&map[i-2][j-2]==1 &&map[i-3][j-3]==1 &&map[i-4][j-4]==1){
                    cout <<"1\n";
                    cout << i+1 <<" "<<j+1;
                    chk=0;
                    break;
                }
            }
            if(map[i][j]==2 && chk){
                if(map[i+1][j]==2 && map[i+2][j]==2 && map[i+3][j]==2 && map[i+4][j]==2){
                    cout << "2\n";
                    cout << i+1 <<" " << j+1;
                    chk=0;
                    break;
                }
                else if(map[i][j+1]==2 && map[i][j+2]==2 && map[i][j+3]==2 && map[i][j+4]==2){
                    cout <<"2\n";
                    cout << i+1 <<" "<<j+1;
                    chk=0;
                    break;
                }
                else if(map[i+1][j+1]==2 &&map[i+2][j+2]==2&&map[i+3][j+3]==2 &&map[i+4][j+4]==2){
                    cout <<"2\n";
                    cout << i+1 <<" "<<j+1;
                    chk=0;
                    break;
                }
                else if(map[i-1][j-1]==2 &&map[i-2][j-2]==2 &&map[i-3][j-3]==2 &&map[i-4][j-4]==2){
                    cout <<"2\n";
                    cout << i+1 <<" "<<j+1;
                    chk=0;
                    break;
                }
            }
        }
    }
    if(chk)cout << "0";
}