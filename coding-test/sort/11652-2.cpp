#include<iostream>
#include<unordered_map>
using namespace std;

unordered_map<long long, int> cards;
int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	int n;
	long long max_cnt = 0;
	long long max_num = 0;
	
	cin >> n;
	
	for(int i=0; i<n; i++){
		long long card;
		
		cin >> card;
		
		auto iter = cards.find(card);
		
		if(iter == cards.end()){
			cards.insert(make_pair(card, 1));

		}else{
			cards[card] += 1;
		}
		
		if(cards[card] > max_cnt || cards[card] == max_cnt && max_num > card){
			max_cnt = cards[card];
			max_num = card;
		}
	}
	
	cout << max_num;
	
	
}
