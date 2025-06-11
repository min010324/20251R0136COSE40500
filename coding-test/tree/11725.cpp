#include<iostream>
#include<vector>

using namespace std;


long n;
vector<long> tree[100005];
long res[100005];
long is_visited[100005] = {0};
void rec(long node){
	is_visited[node] = 1;
	for(const auto& child : tree[node]){
		if(is_visited[child] == 0){
			res[child] = node;
			rec(child);
		}
		
	}
}

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin >> n;
	
	for(long i = 0; i < n-1; i++){
		long from, to;
		cin >> from >> to;
		tree[from].push_back(to);
		tree[to].push_back(from);
	}
	
	rec(1);
	
	for(int i=2; i <=n; i++){
		cout << res[i] << "\n";
	}
	
	

}
