//
// Created by 황정민 on 2024. 11. 19..
//
#include<iostream>
#include <vector>

using namespace std;
int n;
int ans = 0;
int col[15];
bool is_valid(int cur_x, int cur_y, int tar_x, int tar_y){
    if (cur_x == tar_x) return false;
    if (cur_y == tar_y) return false;
    if (cur_x + cur_y == tar_x + tar_y) return false;
    if (cur_x - cur_y == tar_x - tar_y) return false;
    return true;
}

void n_queen(int row) {
    if (row == n + 1){
        ans++;
        return;
    }
    for (int i =1; i <=n; i++){
        bool possible = true;
        for(int j=1; j<row; j++){
            if(!is_valid(row, i, j, col[j])){
                possible = false;
                break;
            }
        }
        if (possible){
            col[row] = i;
            n_queen(row + 1);
            col[row] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    n_queen(1);
    cout << ans;

}