//
// Created by 황정민 on 2024. 11. 20..
//
#include<iostream>
#include<unordered_map>

using namespace std;

long n;
unordered_map<long long, long> card_map;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;

    long max_cnt = 0;
    long long max_num = 0;
    for(long i = 0; i<n; i++){
        long long num;
        cin >> num;
        auto iter = card_map.find(num);
        if(iter == card_map.end()){
            card_map.insert(make_pair(num, 1));
        } else {
            card_map[num] += 1;
        }
        if((card_map[num] > max_cnt) || (card_map[num] == max_cnt && max_num > num)) {
            max_cnt = card_map[num];
            max_num = num;
        }
    }

    cout << max_num;

}