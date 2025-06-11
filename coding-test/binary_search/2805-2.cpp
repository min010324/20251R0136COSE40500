#include<iostream>
#include<vector>

using namespace std;

long n, m;
vector<long> trees;

bool is_possible(int height){
	long sum = 0;
	for(const auto& tree : trees){
		if(tree > height){
			sum += tree - height;
		}
	}
	
	if(sum < m){
		return false;
	}
	return true;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin >> n >> m;
	
	for(long i=0; i<n; i++){
		long tree;
		cin >> tree;
		trees.push_back(tree);
	}
	
	long l, r, ans;
	l = ans = 0;
	r = 1'000'000'000;
	while(l <= r){
		long mid = (l + r) / 2;	
		if(is_possible(mid)){
			ans = mid;
			l = mid + 1;
		} else{
			r = mid - 1;
		}
	}
	
	cout << ans;
}
