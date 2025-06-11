#include<iostream>
#include<string>
#include<vector>
#include<algorithm>


using namespace std;

int n;

typedef struct Student{
	string name;
	int ko;
	int en;
	int math;

} Student;

vector<Student> input;

bool cmp(const Student& a, const Student& b){
	if(a.ko != b.ko){
		return a.ko > b.ko;
	}
	if(a.en != b.en){
		return a.en < b.en;
	}
	if(a.math != b.math){
		return a.math > b.math;
	}
	
	return a.name < b.name;
}


int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin >> n;
	
	for(int i=0; i<n; i++){
		string name;
		int ko, en, math;
		cin >> name >> ko >> en >> math;
		input.push_back({name, ko, en, math});
	}
	
	sort(input.begin(), input.end(), cmp);
	
//	for(int i=0; i<n; i++){
//		cout << input[i].name << "\n";
//	}

	for(const auto& student: input){
		cout << student.name << "\n";
;	}
	

}
