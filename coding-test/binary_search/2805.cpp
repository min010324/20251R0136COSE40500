//
// Created by 황정민 on 2024. 11. 20..
//
#include<iostream>
#include<vector>

using namespace std;

long n, m;
vector<long> tree_list;
const long max_height = 2000000000;

bool is_possible(long h){
    long sum = 0;
    for(const auto& tree: tree_list){
        if(tree > h){
            sum += tree - h;
        }
    }
    return sum >= m;
}

int search(){
    long l, r;
    l = 0;
    r = max_height;
    while (l <= r){
        long mid = (l + r) / 2;
        if(is_possible(mid)){
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    return l-1;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        long h;
        cin >> h;
        tree_list.push_back(h);
    }

    cout << search();

}