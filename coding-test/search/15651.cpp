//
// Created by 황정민 on 2024. 11. 19..
//
#include<iostream>
using namespace std;

int n, m;
int arr[10];
int is_used[10];

void dfs(int k){
    if(k == m){
        for(int i = 0; i<m; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i = 1; i<=n; i++){
        arr[k] = i;
        dfs(k+1);
    }
}

int main(){
    cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m;
    dfs(0);
}
