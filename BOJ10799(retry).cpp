#include <string>
#include <iostream>
#include <stack>
using namespace std;

int main() {
	string str;
	getline(cin, str);
	stack<char> Stack;
	int cnt = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			Stack.push('(');
		}
		if (str[i] == ')') { // �����ϴ� ��츦 �Ű澲��.
			if (str[i - 1] == '(') {
				Stack.pop();
				cnt += Stack.size();
			} // lazer
			else {
				Stack.pop();
				cnt += 1;
			}
		}
	}
	cout << cnt;
}