#include<iostream>
using namespace std;

int num_cnt[10];
int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	long long a, b, c;
	cin >> a >> b >> c;
	
	long long ans;
	ans = a * b* c;
	while(ans > 0){
		int digit;
		digit = ans % 10;
		num_cnt[digit] += 1;
		ans /= 10;
	}
	
	for(int i =0; i<10; ++i){
		cout << num_cnt[i] << "\n";
	}	
		
}
