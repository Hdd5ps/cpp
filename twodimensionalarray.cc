#include<iostream>
using namespace std;

int main(){
    const int ROWS = 3, COLS = 3;
    // char charArray[ROWS][COLS] = {{'1','2','3'},{'0','0','0'},{'j','k','l'}};
    
    // 1 2 3 
    // 0 0 0 
    // j k l 
    char charArray[ROWS][COLS] = {{'1','2'},{'0','0','0'},{'j','k','l'}};
        
    // 1 2  
    // 0 0 0 
    // j k l 

    // need two loops for 2d arrays
    // outer loop - control the row#
    // inner loop - control the col#
    for (int i = 0; i<ROWS; i++){
        for (int j = 0; j<COLS; j++ ){
            cout<<charArray[i][j]<<" ";
        }
        cout<<endl;
    }
}