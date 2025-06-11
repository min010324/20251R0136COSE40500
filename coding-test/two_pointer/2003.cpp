//
// Created by 황정민 on 2024. 11. 21..
//
#include<iostream>
#include<vector>
using namespace std;

long n, m;
vector<int> num_arr;
int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m;
    for(int i =0; i< n; i++){
        int num;
        cin >> num;
        num_arr.push_back(num);
    }

    long r, cnt, sum;
    r = cnt = 0;
    sum = num_arr[0];
    for(int i = 0; i < n; i++){
        if(i != 0){
            sum -= num_arr[i-1];
        }
        while (sum < m && r <= n){
            r++;
//            cout << "prev sum : " << sum <<"\n";
            sum += num_arr[r];
//            cout << "l: " << i << " r: " << r << " sum: " << sum <<  "\n";

        }
        if(sum == m){
//            cout << "##sum l: " << i << " r: " << r << " sum: " << sum <<  "\n";
            cnt++;
        }
    }
    cout << cnt;
}