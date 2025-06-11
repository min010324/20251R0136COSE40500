#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n, k;
	queue<int> q;
	vector<int> res;
	cin >> n >> k;
	for(int i=1; i<=n; ++i){
		q.push(i);
	}
	int cnt = 1;
	while(!q.empty()){
		if(cnt == k){
			res.push_back(q.front());
			q.pop();
			cnt =1;
			continue;
		}
		
		q.push(q.front());
		q.pop();
		cnt++;
	}
	
	cout << '<';
	
	for (size_t i = 0; i < res.size(); ++i) {
        cout << res[i];
        if (i < res.size() - 1) {
            cout << ", ";
        }
    }
	
	cout << '>';
	
}
