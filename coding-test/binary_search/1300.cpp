//
// Created by 황정민 on 2024. 11. 20..
//
#include<iostream>
#include<algorithm>

using namespace std;

long long n, k;


long long order_of(long long target){
    long long cnt = 0;
    for(long long i=1; i<=n; i++){
        cnt += min(target / i, n);
    }
    return cnt;
}

void search(){
    long long l, r, ans = 0;
    l = 1;
    r = n * n;

    while (l <= r){
        long long mid = (l + r) / 2;
        long long order_of_mid = order_of(mid);
//        if(order_of_mid == k){
//            ans = mid;
//            return;
//        }else if(order_of_mid > k){
//            r = mid -1;
//        } else {
//            l = mid + 1;
//        }
        if(order_of_mid < k){
            l = mid + 1;
        }else {
            ans = mid;
            r = mid -1;
        }

    }
    cout << ans;

}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> k;
    search();
}