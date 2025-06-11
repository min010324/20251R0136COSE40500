#include<iostream>
#include<vector>
#include<queue>

using namespace std;


int n, m;
int room_map[10][10];
int minimun = 100;
vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int count_area(){
	int cnt = 0;
	int is_visited[10][10] = {0};

	for(int i = 0; i< n; i++){
		for(int j = 0; j < m ; j++){
			if(room_map[i][j] == 2 && is_visited[i][j] == 0){
				queue<pair<int, int>> cand;
				cand.push(make_pair(i, j)); cnt++;
				is_visited[i][j] = 1;

				while(!cand.empty()){
					auto current = cand.front(); cand.pop();
//                    cout << current.first << " "<< current.second << " " << cnt << "\n";
					for(const auto& direc : directions){
						int dx = current.first + direc[0];
						int dy = current.second + direc[1];
                        if(dx < 0 || dx >= n) continue;
                        if(dy < 0 || dy >= m) continue;
						if(room_map[dx][dy] != 1 && is_visited[dx][dy] == 0){
							cand.push(make_pair(dx, dy));
                            is_visited[dx][dy] = 1;
                            cnt++;
//                            cout << dx << " "<< dy <<" "<< cnt << "\n";
                        }
						
					}
				}
			}
		
		}
	}
	
	return cnt;
}


void rec(int cnt, int x, int y){
	if(cnt == 3){
		int virus = count_area();

        if(virus < minimun){
//            for(int i = 0; i<n; i++){
//                for(int j = 0; j<m; j++){
//                    cout << room_map[i][j] << ' ';
//                }
//                cout << '\n';
//            }
            minimun = virus;
//            cout << minimun << '\n';
//            cout << '\n';
        }
		return;
	}
    
	for(int i = x; i< n; i++){
		for(int j = (i == x ? y : 0); j< m; j++){
			if(room_map[i][j] == 0){
				room_map[i][j] = 1;
				int dy = j + 1;
//				if(dy == m){
//                    room_map[i][j] = 0;
//                    continue;
//				}
				rec(cnt + 1, i, dy);
				room_map[i][j] = 0;
			}
		}
	}
    
    
}


int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> n >> m;
    int wall = 3;
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			int num;
			cin >> num;
            if(num == 1) wall++;
			room_map[i][j]=num;
		}
	}
	
//	cout << count_area();
	rec(0, 0, 0);

    cout << n * m - minimun - wall;
	
}
