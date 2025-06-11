#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	vector<long long> towers;
	stack<int> cand;
	int res[500001] = {0};
	
	int n;
	cin >> n;
	for(int i = 0; i<n; ++i){
		long long height;
		cin >> height;
		towers.push_back(height);
	}
	
	for(int i = n-1; i>=0; --i){
		int current = towers[i];

		while(!cand.empty()){
			int target = cand.top();
			if(towers[target] > current){
				cand.push(i);
				break;
			}
			res[target] = i+1;
			cand.pop();			
		}
		if(cand.empty()){
			cand.push(i);
			continue;
		}
	}
	
	for(int i = 0; i<n; ++i){
		cout << res[i] << " ";
	}
	
	
	
	
	
}
