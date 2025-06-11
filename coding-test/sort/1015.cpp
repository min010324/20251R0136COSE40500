//
// Created by 황정민 on 2024. 11. 20..
//
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int n;
vector<pair<int, int>> arr;
vector<pair<int, int>> arr_sorted;
int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        arr.push_back(make_pair(num, i));
    }
    arr_sorted = arr;
    sort(arr_sorted.begin(), arr_sorted.end());
    for(int i=0; i<n; i++){
        auto iter = find(arr_sorted.begin(), arr_sorted.end(), arr[i]);
        if(iter != arr_sorted.end()){
            int index = iter - arr_sorted.begin();
            cout << index << " ";
        }
    }


}