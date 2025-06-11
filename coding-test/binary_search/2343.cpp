//
// Created by 황정민 on 2024. 11. 20..
//
#include<iostream>
#include<vector>

using namespace std;

long n, m;
vector<long> lectures;

bool is_possible(long time){
    long sum = 0;
    long cnt = 1;
    for(const auto& lecture : lectures){
        if(cnt > m) return false;
        if(lecture > time) return false;
        if(sum + lecture <= time){
            sum += lecture;
        } else {
            sum =lecture;
            cnt++;
        }
    }
    return cnt <= m;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m;
    for(long i=0; i<n; i++){
        long time;
        cin >> time;
        lectures.push_back(time);
    }

    long l, r, ans;
    l = 0;
    r = 1'000'000'000;
    while(l <= r){
        long mid = (l + r)/2;
        if(is_possible(mid)){
            r = mid - 1;
            ans = mid;
        }else {
            l = mid + 1;
        }
    }

    cout << ans;


}