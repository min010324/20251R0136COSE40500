#include<iostream>
#include<string>
#include<stack>

using namespace std;
int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	int n, cnt = 0;
	cin >> n;
	for(int i=0; i< n; ++i){
		string temp;
		cin >> temp;
		stack<char> s;
		for(auto &c : temp){
			if(!s.empty() && s.top() ==  c){
				s.pop();
			}else{
				s.push(c);
			}
		}
		
		if(s.empty()){
			cnt++;
		}
	}
	
	cout << cnt;
	

}
