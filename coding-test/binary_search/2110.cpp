//
// Created by 황정민 on 2024. 11. 20..
//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long n,c;
vector<long> pos_list;

bool is_possible(long d){
    long cnt = 1;
    long prev = pos_list[0];

    for(int i =1; i< pos_list.size(); i++){
        if(cnt >= c){
            break;
        }
        if(pos_list[i] - prev >= d){
            cnt++;
            prev = pos_list[i];
        }
    }
    return cnt >= c;
}

void search(){
    long l, r, ans;
    l = 0;
    r = 1000000000;
    while (l <=r){
        long mid = (l + r) / 2;
        if (is_possible(mid)){
            ans = mid;
            l = mid + 1;
        } else{
            r = mid -1;
        }
    }
    cout << ans;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    cin >> n >> c;
    for(long i =0 ;i <n; i++){
        long pos;
        cin >> pos;
        pos_list.push_back(pos);
    }

    sort(pos_list.begin(), pos_list.end());
    search();
}