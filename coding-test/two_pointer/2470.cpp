//
// Created by 황정민 on 2024. 11. 21..
//
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>

using namespace std;

long n;
vector<long> num_arr;
int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    for(long i=0; i<n; i++){
        long num;
        cin >> num;
        num_arr.push_back(num);
    }

    sort(num_arr.begin(), num_arr.end());
    long l, r, target_l, target_r;
    l = 0;
    r = num_arr.size() - 1;
    long sum = abs(num_arr[r] + num_arr[l]);
    target_l = l;
    target_r = r;
    while (l < r){
        long temp = num_arr[r] + num_arr[l];
//        cout << "temp : " << temp << "(" << abs(temp) << "), " << sum << "\n";
        if(abs(temp) < sum){
            sum = abs(temp);
            target_l = l;
            target_r = r;
//            cout << target_l << " " << target_r << ' ' << sum << '\n';
        }
        if(temp < 0){
            l++;
        }else{
            r--;
        }
    }

//    for(long i=0; i<n; i++){
//        cout << num_arr[i] << ' ';
//    }
//    cout << '\n';
//
//    cout << target_l << " " << target_r << '\n';
    cout << num_arr[target_l] << " " << num_arr[target_r];

}