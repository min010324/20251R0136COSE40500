#include<iostream>
#include<queue>
#include<vector>
using namespace std;

typedef pair<int, int> p;
char map[105][105];
int n;

vector<p> direcs = {
    {-1, 0},  // 상
    {1, 0},   // 하
    {0, -1},  // 좌
    {0, 1}    // 우
};

int bfs(int mode){ // mode = 0 : default, mode = 1 : 적록생맹
	queue<p> q;

    int is_visited[105][105] = {0};  // 방문 여부 배열 초기화
	int cnt = 0;
	
	for(int i=0; i< n; ++i){
		for(int j=0; j< n; ++j){
			char current_color;
			if(is_visited[i][j] == 0){
				is_visited[i][j] = 1;
				q.emplace(i, j);
				current_color = map[i][j];
                if(mode == 1 && current_color == 'G'){
                    current_color = 'R';
                }
				cnt++;
			}
			while(!q.empty()){
				for(const auto& direc : direcs){
					int x, y;
					x = q.front().first + direc.first;
					y = q.front().second + direc.second;
					if(x < 0 || y < 0) {
						continue;
					}
                    char color = map[x][y];
                    if(mode == 1 && color == 'G'){
                        color = 'R';
                    }
                    if(is_visited[x][y] == 0 && color == current_color){
                        q.emplace(x, y);
                        is_visited[x][y] = 1;
                    }
				}
				q.pop();
			}

		}
	}
	
	return cnt;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> n;
	
	for(int i=0; i< n; ++i){
		for(int j=0; j< n; ++j){
			char c;
			cin >> c;
			map[i][j] = c;
		}
	}	
	
	cout << bfs(0) << ' ' << bfs(1);
}
