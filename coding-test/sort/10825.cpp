//
// Created by 황정민 on 2024. 11. 20..
//
#include<iostream>
#include<string>
#include <vector>
#include<algorithm>

using namespace std;

typedef struct Student {
    string name;
    int kor;
    int eng;
    int math;
} Student;

int n;
vector<Student> student_list;

bool cmp(const Student& a, const Student& b){
    if(a.kor != b.kor){
        return a.kor > b.kor;
    }
    if(a.eng != b.eng){
        return a.eng < b.eng;
    }
    if(a.math != b.math){
        return a.math > b.math;
    }
    return a.name < b.name;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        string name;
        int kor, eng, math;
        cin >> name >> kor >> eng >> math;
        student_list.push_back({name, kor, eng, math});
    }
    sort(student_list.begin(), student_list.end(), cmp);

    for(const auto& student : student_list){
        cout << student.name << "\n";
    }

}