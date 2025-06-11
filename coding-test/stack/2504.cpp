#include<iostream>
#include<stack>
#include<string>

using namespace std;

int score[30];

int main(){
	ios::sync_with_stdio();cin.tie(NULL);cout.tie(NULL);
	stack<char> s;
	string content;
	cin >> content;
	
	for(auto & c : content){
        int layer = s.size();
//        cout << layer << " : ";
        if(!s.empty() && s.top() == '(' && c == ')'){ // () 경우
			if(score[layer] == 0){
				score[layer - 1] += 2;
			} else{
				score[layer - 1] += 2 * score[layer];
			}
			score[layer] = 0;
			s.pop();
		} else if(!s.empty() && s.top() == '[' && c == ']'){ // [] 경우
			if(score[layer] == 0){
				score[layer - 1] += 3;
			} else{
				score[layer - 1] += 3 * score[layer];
			}
			score[layer] = 0;
			s.pop();
		}else {
            s.push(c);
        }
		
//		for(int i = 0; i< 30; ++i){
//			cout << score[i] << ' ';
//		}
//		cout << '\n';
	}
	
	if(s.empty()){
		cout << score[0];
	}else{
		cout << 0;
	}
	
	

}

