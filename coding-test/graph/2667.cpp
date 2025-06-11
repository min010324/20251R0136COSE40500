#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int house_map[30][30];
int is_visited[30][30] = {0};
vector<pair<int, int>> directions = {
    {1, 0}, {-1, 0}, {0, 1}, {0, -1}, 
//    {1, 1}, {-1, -1}, {-1, 1}, {1, -1}
};

vector<int> res;
int n, cnt = 0;

void search(int x, int y){
	if(house_map[x][y] == 0) return;
	if(is_visited[x][y] == 1) return;		
	is_visited[x][y] = 1;
	cnt++;
	for(const auto& direction : directions){
		int dx = x + direction.first;
		int dy = y + direction.second;
		if(is_visited[dx][dy] == 0 && house_map[dx][dy]){
			search(dx, dy);
		}
	}
}


int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> n;
	for(int i = 0; i<n; i++){
		string row;
		cin >> row;
		for(int j = 0; j<n; j++){
			house_map[i][j] = stoi(row.substr(j, 1));
		}

	}

	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			cnt = 0;
			search(i, j);
			if(cnt > 0){
				res.push_back(cnt);
			}
			
		}
	}
	
	cout << res.size() << "\n";
	sort(res.begin(), res.end());
	for(const auto& item: res){
		cout << item << "\n";
	}
}



