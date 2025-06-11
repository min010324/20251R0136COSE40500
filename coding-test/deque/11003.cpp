#include <iostream>
#include <deque>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, l;
    cin >> n >> l;
    
    deque<pair<int, int>> dq;
    
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;

        while (!dq.empty() && dq.back().first > num) {
            dq.pop_back();  // 더 큰 값 제거
        }
        dq.emplace_back(num, i);

        if (dq.front().second <= i - l) {
            dq.pop_front();  // 윈도우 밖 제거
        }
        
        cout << dq.front().first << " ";
    }
}
