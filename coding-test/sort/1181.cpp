//
// Created by 황정민 on 2024. 11. 20..
//
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int n;
vector<string> word_list;

bool cmp(const string& a, const string& b){
    if(a.length() != b.length()){
        return a.length() < b.length();
    }
    return a < b;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++){
        string word;
        cin >> word;
        if(find(word_list.begin(), word_list.end(), word) == word_list.end()){
            word_list.push_back(word);
        }
    }
    sort(word_list.begin(), word_list.end(), cmp);

    for(const auto& word: word_list){
        cout << word << "\n";
    }

}