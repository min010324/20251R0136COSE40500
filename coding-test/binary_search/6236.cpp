//
// Created by 황정민 on 2024. 11. 20..
//
#include<iostream>
#include<vector>
using namespace std;

long n, m;
vector<long> money_list;

bool is_possible(long k){
    long cnt, remain;
    cnt = 0;
    remain = 0;

    for(const auto& money : money_list){
        if(money > k) return false;
        if(remain < money){
            remain = k;
            cnt++;
        }
        remain -= money;
    }
    return cnt <= m;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m;
    for(long i=0; i<n; i++){
        long money;
        cin >> money;
        money_list.push_back(money);
    }

    long l, r, ans;
    l = 0;
    r = 1'000'000'000;

    while (l <= r){
        long mid = (l + r)/2;
//        cout << l << " " << mid << " " << r << "\n";
        if(is_possible(mid)){
            ans = mid;
            r = mid -1;
        } else {
            l = mid +1;
        }
    }

    cout << ans;
}