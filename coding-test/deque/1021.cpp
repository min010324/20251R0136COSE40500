#include <iostream>
#include <deque>

using namespace std;

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
    deque<int> dq;  // 빈 deque 생성
    
    int n, m, res = 0;
    
    cin >> n >> m;
    
    for(int i = 1; i<=n; ++i){
    	dq.push_back(i);
    }
    
    for(int i = 0; i< m; ++i){
    	int target;
    	cin >> target;
    	int cnt = 0;
    	while(target != dq.front()){
    		cnt++;
    		dq.push_back(dq.front());
    		dq.pop_front();
    	}

//        cout << "dq.size() : " << dq.size() << " cnt : " <<  cnt;
    	if((dq.size() + 1) / 2 <= cnt){
    		cnt = dq.size() - cnt;
    	}
    	res += cnt;
    	dq.pop_front();
//        cout << " res : " << res << "\n";
    }
    
    cout << res;
	
	
}
