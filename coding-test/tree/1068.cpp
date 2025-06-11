#include<iostream>
#include<vector>

using namespace std;

int n;
vector<int> graph[55];
int root, target;

int traverse(int node, int skip){
	int cnt = 0;
	for(const auto& child : graph[node]){
        if(skip == 1 && child == target) continue;
		cnt += traverse(child, skip);
	}
	return cnt == 0 ? 1 : cnt;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin >> n;
	for(int i=0; i<n; i++){
		int parent;
		cin >> parent;
		if(parent == -1) {
			root = i;
			continue;
		}
		graph[parent].push_back(i);
	}
	
	cin >> target;
    if(root == target){
        cout << 0;
        return 0;
    }
    int cnt = traverse(root, 1);
    cout << cnt;
//	cout << (cnt == 0 ? 1 : cnt);

}
