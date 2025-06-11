//
// Created by 황정민 on 2024. 11. 20..
//

#include<iostream>
#include<algorithm>
#include<vector>
#include <limits>


using namespace std;
int n;
vector<vector<long long>> arr;

bool is_possible(long long num){
    long long cnt = 0;
    for(const auto& temp : arr){
       long long a = temp[0];
       long long b = temp[1];
       long long c = temp[2];
//       if(num <= b){
//           if((num - a) % c == 0){
//               cnt++;
//           }
//       }
        if(num >= a){
            cnt += min(((num - a) / c) + 1, (b - a) / c  + 1);
        }
    }
//    cout << cnt << "\n";
//    if(cnt == 0) return true;
    return cnt % 2 != 0;
}

void search(){
    long l, r, ans = 0;
    l = 1;
    r = 1ll << 31;
    while (l <= r){
        long long mid = (l + r) / 2;
//        cout << l << " " << mid << " " << r << "\n";
        if(is_possible(mid)){
            ans = mid;
            r = mid -1;
        }else {
            l = mid + 1;
        }
    }
    long long cnt = 0;
    for(const auto& temp : arr){
        long long a = temp[0];
        long long b = temp[1];
        long long c = temp[2];
        if(ans >= a){
            if(a <= ans && b >= ans ){
                if((ans - a) % c == 0) cnt++;
            }

        }
    }
    if(ans == 0 && cnt == 0) {
        cout << "NOTHING";
        return;
    }
    cout << ans << " " << cnt;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    cin >> n;
    for(int i = 0; i< n; i++){
        long a, b, c;
        cin >> a >> b >>c;
        vector<long long> temp = {a, b, c};
        arr.push_back(temp);
    }
    search();

}
