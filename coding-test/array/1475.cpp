#include<iostream>
using namespace std;

int num_arr[10];

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n;
	cin >> n;
	
	while(n > 0){
		int digit;
		digit = n %10;
		num_arr[digit] += 1;
		n /= 10;
	}
	
	int max = 0;
	for(int i = 0; i< 10; ++i){
		if(i == 6 || i == 9){
			continue;
		}
		if(num_arr[max] < num_arr[i]){
			max = i;
		}
	}
	int temp = num_arr[6] + num_arr[9];
	int temp_cnt = (temp + 1) / 2;
	if(temp_cnt > num_arr[max]){
		cout << temp_cnt;
	}else {
		cout << num_arr[max];
	}
}
