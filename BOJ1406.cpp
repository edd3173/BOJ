#include <iostream>
#include <string>
#include <stack>
#include <cstring>
using namespace std;

int main() {
	// | �� �������� ������ ������ �ݴ뿩�� �ҵ�? �´�!
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
			if (!Left.empty()) { // �Ű�������!
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
	// �� ������ ������ �����϶�, ����� ���? ���� ���ÿ� ���Ƽ�!
	// ���� ������ ���, �ٸ� ���ÿ� ��������� ��� ����!
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