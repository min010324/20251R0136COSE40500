#include<iostream>
#include<string>
#include<limits.h>
#include<algorithm>

using namespace std;

int t;
int dp[501][501];
int sum[501];

//int dpf(int x, int y){
//	if(dp[x][y] != )

//}

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	cin >> t;
	for(int i = 0; i< t; i++){
		int k;
		cin >> k;

//		memset(dp, 0x3f, sizeof(dp));
		int paper[501];
		for(int j = 1; j<= k; j++){
			int size = 0;
			cin >> size;
			paper[j] = size;
			sum[j] = sum[j - 1] + paper[j];
		}

		for(int d = 1; d<k; ++d){
			for(int x = 1; x <=k-d; ++x){
				int y = x + d;
				dp[x][y] = INT_MAX;

//                cout << x << " " << y << "\n";

				for(int mid = x; mid < y; ++mid){
					dp[x][y] = min(dp[x][y], dp[x][mid] + dp[mid+1][y] + sum[y] - sum[x-1]);
				}
			}
		}

		cout << dp[1][k] << "\n";



	}
}
