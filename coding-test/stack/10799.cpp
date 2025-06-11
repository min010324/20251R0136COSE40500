#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	stack<char> s;
	string content;
	cin >> content;
	int cnt = 0;
	char before;
	
	for(auto & c: content){
		if(!s.empty() && c == ')' && before == '('){ // 레이저로 자르는 경우
			s.pop();
			cnt += s.size();
		}
		
		if(before == ')' && c == ')'){  // 막대 끝인 경우 1 추가
			s.pop();
			cnt++;
		}
		
		if(c == '('){
			s.push('(');
		}
		
		before = c;
	}
	
	cout << cnt;

}
