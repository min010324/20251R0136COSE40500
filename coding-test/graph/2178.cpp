#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;

int n, m;
vector<vector<int>> map_arr;
vector<vector<int>> is_visited;
vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

// int dist = 10001; for dfs
int dist = 0;
void traverse_dfs(int x, int y, int cnt){
	if(x == n -1 && y == m - 1){
		if(cnt < dist){
			dist = cnt;
		}
		return;
	}
	
	if(cnt > dist) return;
	
	for(const auto& direc : directions){
		int dx = x + direc[0];
		int dy = y + direc[1];
		
		if(dx < 0 || dx >= n) continue;
		if(dy < 0 || dy >= m) continue;
		if(is_visited[dx][dy] == 0 && map_arr[dx][dy] == 1){
			is_visited[dx][dy] = 1;
			traverse_dfs(dx, dy, cnt+1);
			is_visited[dx][dy] = 0;
		}
		
	}
}

void traverse_bfs(){
	queue<pair<pair<int, int>, int>> cand;
	cand.push(make_pair(make_pair(0, 0), 1));
	
	while(!cand.empty()){
		auto current = cand.front(); cand.pop();
		if(current.first.first == n-1 && current.first.second == m-1){
			dist = current.second;
			return;
		}
		
		for(const auto& direc : directions){
			int dx = current.first.first + direc[0];
			int dy = current.first.second + direc[1];
			
			if(dx < 0 || dx >= n) continue;
			if(dy < 0 || dy >= m) continue;	
			if(is_visited[dx][dy] == 0 && map_arr[dx][dy] == 1){
				is_visited[dx][dy] = 1;
				cand.push(make_pair(make_pair(dx, dy), current.second + 1));
			}
		}	
	}
}

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin >> n >> m;
	
	for(int i =0; i<n; i++){
		vector<int> temp_row;
		vector<int> is_visited_row;
		string row;
		cin >> row;
		for(int j =0; j<m; j++){
			temp_row.push_back((row[j] - '0'));
			is_visited_row.push_back(0);
		}
		map_arr.push_back(temp_row);
		is_visited.push_back(is_visited_row);
	}
	is_visited[0][0] = 1;
//	traverse_dfs(0, 0, 1);
	traverse_bfs();
	cout << dist;
	
	
}
