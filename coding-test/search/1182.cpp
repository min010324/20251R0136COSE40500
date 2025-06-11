//
// Created by 황정민 on 2024. 11. 19..
//
#include<iostream>
#include<vector>
using namespace std;

int n, s;
vector<int> arr;
int ans = 0;
int is_used[24];
void rec(int d, int sum){
    if(d != 0 && sum == s) {
        ans++;
    }
    if(d == n){
        return;
    }
    for(int i=d; i<n; i++){
        if (is_used[i] == 0){
            is_used[i] = 1;
            rec(i + 1, sum + arr[i]);
            is_used[i] = 0;
        }
    }

}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> s;
    for(int i =0 ; i<n; i++){
        int num;
        cin >> num;
        arr.push_back(num);
    }
    rec(0, 0);
    cout << ans;
}