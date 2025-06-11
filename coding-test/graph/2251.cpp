#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

int is_possible[205][205][205] = {0};

int bucket_max[3];

vector<vector<int>> from_to = {{0, 1}, {0, 2}, {1, 0}, {1, 2}, {2, 0}, {2, 1}};
set<int> res;

void rec(int bucket[3]){
	is_possible[bucket[0]][bucket[1]][bucket[2]] = 1;
	if(bucket[0] == 0) res.insert(bucket[2]);
	
	for(const auto& item : from_to){
        int temp[3] = {bucket[0], bucket[1], bucket[2]};
//        cout << "prev " << bucket[0] << " " << bucket[1] << " " << bucket[2] << "\n";
		if(bucket[item[0]] > bucket_max[item[1]] - bucket[item[1]]){ // from > to
			temp[item[0]] -= bucket_max[item[1]] - bucket[item[1]];
			temp[item[1]] = bucket_max[item[1]];
		} else { // from <= to
			temp[item[1]] += bucket[item[0]];
			temp[item[0]] = 0;
		}
//        cout << "next " << bucket[0] << " " << bucket[1] << " " << bucket[2] << "\n";
		if(is_possible[temp[0]][temp[1]][temp[2]] == 0){
//            cout << "possible " << bucket[0] << " " << bucket[1] << " " << bucket[2] << "\n";
			rec(temp);
		}
	}
}

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int bucket[3] = {0};
	for(int i=0; i< 3; i++){
		cin >> bucket_max[i];
	}
    bucket[2] = bucket_max[2];

	rec(bucket);
//	sort(res.begin(), res.end());
	for(const auto& item : res){
		cout << item << " ";
	}
		
}
