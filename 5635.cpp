#include<iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,max=0,min=0;
    char name[101][16];
    int birth[101][4];
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> name[i] >> birth[i][2] >> birth[i][1] >> birth[i][0];
    }
    //find min
    for(int i=1;i<n;i++)
    {
        if(birth[min][0]<birth[i][0])min=i;
        else if(birth[min][0]==birth[i][0]){

            if(birth[min][1]<birth[i][1])min=i;
            else if(birth[min][1]==birth[i][1]){

                if(birth[min][2]<birth[i][2])min=i;
            }
        }
    }
    for(int i=1;i<n;i++)
    {
        if(birth[max][0]>birth[i][0])max=i;
        else if(birth[max][0]==birth[i][0]){

            if(birth[max][1]>birth[i][1])max=i;
            else if(birth[max][1]==birth[i][1]){
                
                if(birth[max][2]>birth[i][2])max=i;
            }
        }
    }
    cout << name[min] <<"\n" <<name[max];
}