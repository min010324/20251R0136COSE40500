//
// Created by 황정민 on 2024. 11. 20..
//

#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;
int n;

map<string, int> file_list;

int main(){
    cin >> n;

    for(int i=0; i<n; i++){
        string file, buffer, name, type;
        cin >> file;
        auto idx = file.find('.');
        if(idx != string::npos){
            name = file.substr(0, idx);
            type = file.substr(idx + 1);
        }

        auto iter = file_list.find(type);
        if(iter != file_list.end()){
            file_list[type] += 1;
        } else {
            file_list[type] = 1;
        }
    }


    for(const auto& file: file_list){
        cout << file.first << " " << file.second << "\n";
    }
}

