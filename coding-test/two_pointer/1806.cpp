//
// Created by 황정민 on 2024. 11. 20..
//
#include<iostream>
#include<vector>
using namespace std;

long n, s;
vector<long> num_arr;

long sum(long start, long end){
    long temp = 0;
    for(long i = start; i<=end; i++){
        temp += num_arr[i];
    }
    return temp;
}

int main(){
        ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> s;
    long total_sum = 0;
    for(long i = 0; i< n; i++){
        long num;
        cin >> num;
        num_arr.push_back(num);
        total_sum += num;
    }

    if(total_sum < s){
        cout << 0;
        return 0;
    }

    long r = 0, ans = n, sub_sum = num_arr[0];
    for(long i = 0; i<n;i++){
        if(i != 0){
            sub_sum -= num_arr[i - 1];
        }
//        long sub_sum = sum(i, r);
        while (sub_sum < s && r <= n){
//            cout << "sub sum : " << sub_sum << "\n";
            r++;
            sub_sum += num_arr[r];
//            sub_sum = sum(i, r);
        }
        if(sub_sum >= s){
//            cout << i << ' ' << r << '\n';
            long temp = r - i + 1;
//            cout  << "temp: " << temp << " ans: " << ans << '\n';
            if(temp < ans){
                ans = temp;
            }
        }
    }
    cout << ans;
}
