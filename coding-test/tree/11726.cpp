#include<iostream>

using namespace std;

int dp[1001];

int dpf(int n){
	if(n == 1) return dp[1] = 1;
	if(n == 2) return dp[2] = 2;
	if(dp[n] != 0) return dp[n];
	
	return dp[n] = (dpf(n-1) + dpf(n-2)) % 10007;
}


int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	int n;
	cin >> n;
	cout << dpf(n);
}
