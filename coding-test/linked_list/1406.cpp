#include<iostream>
#include<string>
#include<stack>

using namespace std;


int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	string input = "";
	cin >> input;
	
	int n;
	cin >> n;

    stack<char> left;
    stack<char> right;

	
	for(const char c : input){
		left.push(c);
	}
	
	for(int i = 0; i<n; ++i){
		string cmd;
		cin >> cmd;
        if (cmd == "L") {
            if (!left.empty()) {
                right.push(left.top());
                left.pop();
            }
        } else if (cmd == "D") {
            if (!right.empty()) {
                left.push(right.top());
                right.pop();
            }
        } else if (cmd == "B") {
            if (!left.empty()) {
                left.pop();
            }
        } else if (cmd == "P") {
            char c;
            cin >> c;
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
	cout << endl;

	
}
