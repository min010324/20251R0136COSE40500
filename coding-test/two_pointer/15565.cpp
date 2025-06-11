//
// Created by 황정민 on 2024. 11. 21..
//
#include<iostream>
#include<vector>

using namespace std;
long n, k;
vector<long> lion_idx;
int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> k;
    for(int i=0; i< n;i++){
        int num;
        cin >> num;
        if(num == 1) lion_idx.push_back(i);
    }

    if(lion_idx.size() < k) {
        cout << -1;
        return 0;
    }
    long minimum = lion_idx[0+k-1] - lion_idx[0] + 1;
    for(int i=0; i<=lion_idx.size() - k; i++){
        long temp = lion_idx[i+k-1] - lion_idx[i] + 1;
        if(temp < minimum) minimum = temp;
    }
    cout << minimum;



}