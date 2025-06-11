#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

int l, c;

vector<char> input;
set<char> must_have = {'a', 'e', 'i', 'o', 'u'};
char ans[20];
void dfs(int n, int prev){
	if ( n == l ){
		int count = 0;
		
		for(int i =0; i<l; i++){
			if(must_have.count(ans[i])){
				count++;
			}
		}
		
		if(count < 1 || l-count < 2){
			return;
		}

        cout << ans << "\n";
		return;
	}
	
	for(int i=prev + 1; i<c; i++){
		ans[n] = input[i];
		dfs(n+1, i);
	}
	
	

}

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin >> l >> c;
	
	for(int i=0; i<c; i++){
		char temp;
		cin >> temp;
		input.push_back(temp);
	}
	
	sort(input.begin(), input.end());
	
	dfs(0, -1);
	
}
