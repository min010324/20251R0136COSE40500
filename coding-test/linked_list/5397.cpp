#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	int n;
	
	cin >> n;
	
	for(int i = 0; i< n; ++i){
		stack<char> left, right;
		string input;
		cin >> input;
		for(const char c : input){
			if(c == '<'){
				if(!left.empty()){
					right.push(left.top());
					left.pop();
				}
			} else if(c == '>'){
				if(!right.empty()){
					left.push(right.top());
					right.pop();
				}
			} else if(c == '-'){
				if(!left.empty()){
					left.pop();
				}
			} else {
				left.push(c);
			}
		}
		
		
		while(!left.empty()){
			right.push(left.top());
			left.pop();
		}
		
		while(!right.empty()){
			cout << right.top();
			right.pop();
		}
		cout << "\n";
	}

}
