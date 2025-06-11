//
// Created by 황정민 on 2024. 11. 19..
//
#include<iostream>
using namespace std;

int n, m;
int arr[10] = {};
int is_used[10] = {};

void dfs(int k, int prev) {
    if(k == m){
        for(int i = 0; i < m; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
    }

    for(int i=prev; i<=n; i++){
        if(is_used[i] == 0) {
            is_used[i] = 1;
            arr[k] = i;
            dfs(k+1, i);
            is_used[i] = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    dfs(0, 1);
}