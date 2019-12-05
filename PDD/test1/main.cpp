#include <iostream>
#include <cstdio>
using namespace std;


int changeX[4] = {1,-1,0,1};
int changeY[4] = {0,1,1,-1};


void func(int encode[25],int decode[5][5]){

    int num = 0;
    int x = 0;
    int y = 0;
    int choice = 0;
    int rows = 5;
    int cols = 5;


    while(num < 25){

        if( !(x + changeX[choice] < rows)){
            choice = (choice + 2) % 4;
        }
        else if(  !(y + changeY[choice] <  cols)){
            choice = (choice + 2) % 4;
        }

        if(choice == 0 || choice == 2){
            decode[x][y] = encode[num];
            num++;
            x += changeX[choice];
            y += changeY[choice];
        }
        else if(choice == 1){
            while ( x > 0 && y < cols - 1 && num < 25){
                decode[x][y] = encode[num];
                num++;
                x += changeX[choice];
                y += changeY[choice];
            }
        }
        else if(choice == 3){
            while ( y > 0 && x < rows - 1 && num < 25){
                decode[x][y] = encode[num];
                num++;
                x += changeX[choice];
                y += changeY[choice];
            }
        }

        choice  = (choice + 1) % 4;
    }


}

int main() {
    int encode[25];
    int decode[5][5];
    for (int i = 0; i < 25; ++i) {
        encode[i] = i;
    }

    func(encode,decode);
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            printf("%5d",decode[i][j]);
        }
        cout<<endl;
    }


    return 0;
}