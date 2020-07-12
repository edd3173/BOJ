#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool checkStr(string buf) {
	int flag = 1;
	stack<char> Stack;
	flag = 1; // FLAG�� �ʱ�ȭ�� ���� ���� ��������!
	for (int j = 0; j < buf.length(); j++) {
		if (buf[j] == '(') {
			Stack.push(buf[j]);
		}
		if (buf[j] == ')') {
			if (Stack.empty()) {
				flag = 0;
			}
			else
				Stack.pop();
		}
	}
	if (flag == 0)
		return false;
	else {
		if (Stack.empty())
			return true;
		else
			return false;
	}
} // �Լ��� call �ϴ� �͵� iteration�� ������!

int main() {
	int tc;
	cin >> tc;
	cin.ignore(); // we learned before.
	string buf;

	for (int i = 0; i < tc; i++) {
		getline(cin, buf);
		if (checkStr(buf))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}