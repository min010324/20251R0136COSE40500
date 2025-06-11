//
// Created by 황정민 on 2024. 11. 18..
//
#include <iostream>
using namespace std;

int n, m;
int num_place[10];
int is_used[10];
void dfs(int k) {
    if (k == m){
        for(int i = 0; i<m; i++){
            cout << num_place[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i=1; i<=n; i++){
        if(is_used[i] == 0){
            num_place[k] = i;
            is_used[i] = 1;
            dfs(k+1);

            is_used[i] = 0;
        }
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> n >> m;
    dfs(0);
}