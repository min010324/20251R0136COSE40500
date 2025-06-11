//
// Created by 황정민 on 2024. 11. 19..
//
#include<iostream>
#include<algorithm>
#include <vector>
#include <set>

using namespace std;

int l, c;
vector<char> input;
char ans[20];
set<char> must_have = {'a', 'e', 'i', 'o', 'u'};
void rec(int k, int prev){
    if (k == l){
        int count = 0;
        for(int i = 0; i<l; i++){
             if(must_have.count(ans[i])){
                count++;
             }
        }
        if(!(count > 0 && l - count > 1)){
            return;
        }

//        for(int i = 0; i<l; i++){
//            cout << ans[i];
//        }
        cout << ans;
        cout << "\n";
        return;
    }

    for(int i = prev + 1; i < c; i++){
        ans[k] = input[i];
        rec(k+1, i);
    }

}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> l >> c;
    for (int i = 0; i < c; ++i) {
        char ch;
        cin >> ch;
        input.push_back(ch);
    }

    sort(input.begin(), input.end());

    rec(0, -1);






}