#include <bits/stdc++.h>
using namespace std;

bool visited[25][25];
int board[25][25], targetx, targety;
int point = 0;
int r, c;


void scorepts(int x, int y, int target){
    if (x < 0 || x >= r || y < 0 || y >= c ){
        return;
    }
    else {
        if (visited[x][y]){
            return;
        }
        else{
            if (board[x][y] == target){
                visited[x][y] = true;
                point = point + 1;
                scorepts(x - 1, y,target);
                scorepts(x + 1, y,target);
                scorepts(x,y - 1, target);
                scorepts(x,y + 1, target);  

            }
        }
        
    }
}


int main(){
    scanf("%d %d", &r, &c);

    for (int i = 0; i < r; i++){
        for (int j = 0; j < c;j++){
            scanf("%d", &board[i][j]);
        }
    }
    scanf("%d %d", &targetx, &targety);

    int target = board[targetx][targety];

    scorepts(targetx, targety, target);
    printf("%d", point * (point - 1));
    
    return 0;
}