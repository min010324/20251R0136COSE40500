//
// Created by 황정민 on 2024. 11. 21..
//
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int n, m, v;
vector<int> adj[1005];
int is_visted[1005] = {0};

void dfs(int node){
    cout << node << " ";
    is_visted[node] = 1;
    for(const auto& neighbor : adj[node]){
        if(is_visted[neighbor] == 0){
            dfs(neighbor);
        }
    }
}

void bfs(int node){
    queue<int> queue;
    queue.push(node);
    is_visted[node] = 1;
    while (!queue.empty()){
        int current = queue.front(); queue.pop();
        cout << current << " ";
        for(const auto& neighbor : adj[current]){
            if(is_visted[neighbor] == 0){
                queue.push(neighbor);
                is_visted[neighbor] = 1;
            }
        }
    }

}
int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m >> v;

    for(int i =0; i < m; i++){
        int v1, v2;
        cin >> v1 >> v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }
    for(int i =0; i <= n; i++){
        sort(adj[i].begin(), adj[i].end());
    }
    dfs(v);
    for(int i =0; i <= n; i++){
        is_visted[i] = 0;
    }
    cout << "\n";
    bfs(v);

}