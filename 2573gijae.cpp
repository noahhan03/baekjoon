#include <iostream>
using namespace std;

bool chunkcheck(int** arr, int row, int col){
    int cnt = 0;
    for(int i = 0 ; i < row ; i++){
        for(int j = 0 ; j < col ; j++){
            if(arr[i][j] != 0){
                if(i == 0){
                    if(j == 0){
                        if(arr[i][j+1]==0 && arr[i+1][j] == 0){
                            cnt++;
                        }
                    }else if(j == col-1){
                        if(arr[i][j-1]==0 && arr[i+1][j]==0){
                            cnt++;
                        }
                    }else{
                        if(arr[i][j-1]==0 && arr[i+1][j]==0 && arr[i][j+1]==0){
                            cnt++;
                        }
                    }
                }else if(i == row-1){
                    if(j == 0){
                        if(arr[i][j+1]==0 && arr[i-1][j] == 0){
                            cnt++;
                        }
                    }else if(j == col-1){
                        if(arr[i][j-1]==0 && arr[i-1][j]==0){
                            cnt++;
                        }
                    }else{
                        if(arr[i][j-1]==0 && arr[i-1][j]==0 && arr[i][j+1]==0){
                            cnt++;
                        }
                    }
                }else{
                    if(arr[i][j-1]==0 && arr[i-1][j]==0 && arr[i][j+1]==0 && arr[i+1][j]==0){
                        cnt++;
                    }
                }
            }
        }
    }
    if(cnt >= 2){
        return true;
    }else{
        return false;
    }
}
void reduceyear(int** arr, int row, int col){
    for(int i = 0 ; i < row ; i++){
        for(int j = 0 ; j < col ; j++){
            int cnt = 0;
            if(arr[i][j] != 0){
                if(i == 0){
                    if(j == 0){
                        if(arr[i][j+1]!=0){
                            cnt++;
                        }
                        if(arr[i+1][j]!=0){
                            cnt++;
                        }
                    }else if(j == col-1){
                        if(arr[i][j-1]!=0){
                            cnt++;
                        }
                        if(arr[i+1][j]!=0){
                            cnt++;
                        }
                    }else{
                        if(arr[i][j-1]!=0){
                            cnt++;
                        }
                        if(arr[i][j+1]!=0)cnt++;
                        if(arr[i+1][j]!=0)cnt++;
                    }
                }else if(i == row-1){
                    if(j == 0){
                        if(arr[i][j+1]!=0){
                            cnt++;
                        }
                        if(arr[i-1][j]!=0){
                            cnt++;
                        }
                    }else if(j == col-1){
                        if(arr[i][j-1]!=0){
                            cnt++;
                        }
                        if(arr[i-1][j]!=0){
                            cnt++;
                        }
                    }else{
                        if(arr[i][j-1]!=0){
                            cnt++;
                        }
                        if(arr[i][j+1]!=0)cnt++;
                        if(arr[i-1][j]!=0)cnt++;
                    }
                }else{
                    if(arr[i][j+1]!=0)cnt++;
                    if(arr[i][j-1]!=0)cnt++;
                    if(arr[i+1][j]!=0)cnt++;
                    if(arr[i-1][j]!=0)cnt++;
                }
            }
            while(arr[i][j]!=0){
                for(int i = 1 ; i <= cnt ; i++){
                    arr[i][j] -= i;
                }
            }
        }
    }
}

int main(){
    int row, col, year = 0;
    cin >> row >> col;
    int** arr = new int*[row];
    for(int i = 0 ; i < row ; i++){
        arr[i] = new int[col];
    }
    for(int i = 0 ; i < row ; i++){
        for(int j = 0 ; j < col ; j++){
            cin >> arr[i][j];
        }
    }
    while(1){
        int cnt = 0;
        if(chunkcheck(arr,row,col)){
            cout << year;
            break;
        }
        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){
                if(arr[i][j] != 0){
                    cnt++;
                }
            }
        }
        if(cnt == 0){
            cout << "0";
            break;
        }
        reduceyear(arr,row,col);
        year++;
    }
    return 0;
}