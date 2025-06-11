#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<pair<int, int>> graph[1005]; //node, dist
vector<pair<int, int>> question;
int n, m;
long dist[1005]; 
long is_visited[1005] = {0}; 

struct Compare{
	bool operator()(pair<long, long> a, pair<long, long> b){
		return a.second > b.second;
	}
};

void di(){
	priority_queue<pair<long, long>, vector<pair<long, long>>, Compare> pq; // dist, node
	pq.push(make_pair(0, 1));
	is_visited[1] = 1;
	while(!pq.empty()){
		auto current = pq.top(); pq.pop();
		dist[current.second] = current.first;
		
		for(const auto& neighber: graph[current.second]){
			if(is_visited[neighber.first] == 0){
				pq.push(make_pair(current.first + neighber.second, neighber.first));
				is_visited[neighber.first] = 1;
			}
			
		}
	}

}

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin >> n >> m;
	for(int i=0; i<n-1; i++){
		int v1, v2, d;
		cin >> v1 >> v2 >> d;
		graph[v1].push_back(make_pair(v2, d));
		graph[v2].push_back(make_pair(v1, d));
	}
	
	for(int i=0; i<m; i++){
		int v1, v2;
		cin >> v1 >> v2;
		question.push_back(make_pair(v1, v2));
	}
	
	
	
	
	
//	for(int i = 1; i<=n; i++){
//		cout << dist[i] << " ";
//	}
	
	
}
