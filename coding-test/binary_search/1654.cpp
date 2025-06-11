#include<iostream>
#include<vector>

using namespace std;

long k, n;
vector<long> items;

bool is_possible(long length){
	long sum = 0;
	for(const auto& item : items){
		sum += item / length;
	}
	
	if(sum < n){
		return false;
	}
	
	return true;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin >> k >> n;
	for(long i = 0; i< k; i++){
		long item;
		cin >> item;
		items.push_back(item);
	}
	
	long l, r, ans;
	l = ans = 0;
	r = 1ll << 31;
	
	while(l <= r){
		long mid = (l + r) / 2;
		
		if(is_possible(mid)){
			ans = mid;
			l = mid + 1;
		}else{
			r = mid - 1;
		}
	}
	
	cout << ans;
}
