#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> tree[100001];
vector<int> ans;
int n, r, q;
int is_visited[100001] = {0};
int parents_node[100001] = {0};
int tree_size[100001] = {0};

int dpf(int node) {
	if(tree_size[node] != 0) return tree_size[node];
	int size = 1;
	for(const auto& child : tree[node]){
		if(parents_node[node] == child) continue;
		size += dpf(child);
	}
	
	return	tree_size[node] = size;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin >> n >> r >> q;
	
	for(int i = 1; i< n; ++i){
		int u, v;
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	
	queue<int> bfs_cand;
	bfs_cand.push(r);
	is_visited[r] = 1;
	while(!bfs_cand.empty()){
		int current = bfs_cand.front(); bfs_cand.pop();
		bool is_leaf = true;
		for(const auto child : tree[current]){
			if(is_visited[child] == 1) continue;
			parents_node[child] = current; // 부모 노드 기록
			is_visited[child] = 1; // 방문 처리
			bfs_cand.push(child);
			is_leaf = false; // leaf가 아님
		}
		if(is_leaf) tree_size[current] = 1;
	}
	
	for(int i = 0; i< q; ++i){
        int query;
        cin >> query;
		cout << dpf(query) << "\n";
	}
}
