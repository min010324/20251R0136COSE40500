#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    vector<int> num_arr(10000001, 0);
    vector<int> res(10000001, -1);
    stack<int> cand;

    int n;
    cin >> n;
    for(int i = 1; i<=n; ++i){
        int num;
        cin >> num;
        num_arr[i] = num;
    }

    for(int i = 1; i<=n; ++i){
        int current = num_arr[i];

        while(!cand.empty()){
            int target = cand.top();
            if(num_arr[target] >= current){
                cand.push(i);
                break;
            }
            res[target] = num_arr[i];
            cand.pop();
        }

        if(cand.empty()){
            cand.push(i);
            continue;
        }

    }

    for(int i = 1; i<=n; ++i){
        cout << res[i] << " ";
    }

}
