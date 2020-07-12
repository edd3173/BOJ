#include <iostream>
#include <string>
#include <stack>
#include <cstring>
using namespace std;

int main() {
	// | 를 기준으로 스택의 방향이 반대여야 할듯? 맞다!
	stack<char> Left;
	stack<char> Right;
	string str;
	string result;
	int iter;
	char cmd;
	char input;
	getline(cin, str);
	for (int i = 0; i < str.size(); i++)
		Left.push(str[i]);
	cin >> iter;
	for (int i = 0; i < iter; i++) {
		cin >> cmd;
		char tmp;
		switch (cmd) {
		case 'L':
			//move left
			if (!Left.empty()) { // 신경써줘야함!
				tmp = Left.top();
				Right.push(tmp);
				Left.pop();
			}
			break;
		case 'D':
			//move right
			if (!Right.empty()) {
				tmp = Right.top();
				Left.push(tmp);
				Right.pop();
			}
			break;
		case 'B':
			// delete leftside
			if(!Left.empty())
				Left.pop();
			break;
		case 'P':
			// add to stack
			cin >> input;
			//get input
			Left.push(input);
		}
	}
	// 두 스택의 방향이 역순일때, 출력은 어떻게? 한쪽 스택에 몰아서!
	// 역순 스택의 경우, 다른 스택에 집어넣으면 출력 가능!
	while (!Left.empty()) { 
		Right.push(Left.top());
		Left.pop();
	}

	while (!Right.empty()) {
		cout << Right.top();
		Right.pop();
	}
	cout << endl;
	return 0;
}