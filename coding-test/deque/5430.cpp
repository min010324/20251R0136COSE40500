#include <iostream>
#include <string>
#include <deque>

using namespace std;

deque<int> parseToVector(const string& input) {
    deque<int> result;
    string temp = "";

    for (char ch : input) {
        if (isdigit(ch)) {  // 숫자인 경우
            temp += ch;
        } else if (!temp.empty()) { // 숫자가 끝났을 때
            result.push_back(stoi(temp)); // 문자열을 숫자로 변환 후 벡터에 저장
            temp = ""; // temp 초기화
        }
    }

    // 마지막 숫자 처리
    if (!temp.empty()) {
        result.push_back(stoi(temp));
    }

    return result;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    deque<int> dq;  // 빈 deque 생성

    int t;
    cin >> t;

    for(int i = 0; i<t; ++i){
        int mode = 0; // 0 == front, 1 == back
        string cmd;
        cin >> cmd;

        int n;
        cin >> n;

        string input;
        cin >> input;
        deque<int> result = parseToVector(input);

        bool is_error = false;
        for(const auto& c: cmd){
            if(c == 'R'){
                mode = mode == 0 ? 1 : 0;
            } else if( c == 'D'){
                if (result.empty()){
                    is_error = true;
                    break;
                }
                if(mode == 0){ // front
                    result.pop_front();
                } else { // back
                    result.pop_back();
                }
            }
        }


        if(is_error){
            cout << "error" << "\n";
        } else{
            cout << "[";
            if (mode == 0){
                for (size_t j = 0; j < result.size(); j++) {
                    cout << result[j];
                    if (j < result.size() - 1) {
                        cout << ",";
                    }
                }
            } else {
                for (int j = result.size() - 1; j >= 0; j--) {
                    cout << result[j];
                    if (j > 0) {
                        cout << ",";
                    }
                }
            }
            cout << "]\n";
        }
    }

}
