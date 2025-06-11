#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> ans;

int binary_search(const vector<int>& target_arr, int num) {
	int l, r;
    int ans = -1;
	l = 0;
	r = target_arr.size() - 1;

	
	while(l <= r){
		int mid = (l + r) / 2;
		
		if(target_arr[mid] < num){
            ans = mid;
            l = mid + 1;
		} else {
			r= mid-1;
		}
	}
	
//	cout << ans << " " << target_arr[ans] << "\n";
    return ans + 1;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	int t;	
	cin >> t;
	for(int i=0; i< t; i++){
		int n, m;
		vector<int> n_arr;
		vector<int> m_arr;
		
		cin >> n >> m;
		for(int j=0; j< n; j++){
			int temp;
			cin >> temp;
			n_arr.push_back(temp);
		}
		
		for(int j=0; j< m; j++){
			int temp;
			cin >> temp;
			m_arr.push_back(temp);
		}
		sort(m_arr.begin(), m_arr.end());
		int sum = 0;
		for(int j=0; j< n; j++){
			sum += binary_search(m_arr, n_arr[j]);
		}
        cout << sum << "\n";
	}

}
