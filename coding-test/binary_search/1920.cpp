//
// Created by 황정민 on 2024. 11. 20..
//
#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>


using namespace std;

int n, m;
unordered_set<long> arr;
vector<int> res;
int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++){
        long num;
        cin >> num;
        arr.insert(num);
    }
    cin >> m;
    for(int i=0; i<m; i++){
        long num;
        cin >> num;

        auto iter = arr.find(num);
        if(iter != arr.end()){
            res.push_back(1);
        }else{
            res.push_back(0);
        }
    }

    for(const auto& item: res){
        cout << item <<"\n";
    }
}