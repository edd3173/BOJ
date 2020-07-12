#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	int tc;
	cin >> tc;
	char c;
	string buf;
	stack<char> Stack;
	cin.get(); // cin.ignore() À» ¾µ °Í!
	for (int i = 0; i < tc; i++) {
		getline(cin, buf);
		//cout << "your input : " << buf << endl;
		// input string

		for (int j = 0; j < buf.size(); j++) {
			if (buf[j] != ' ') {
				Stack.push(buf[j]);
			}
			if (buf[j] == ' ' || j==buf.size()-1) {
				while (!Stack.empty()) {
					c = Stack.top();
					cout << c;
					Stack.pop();
				}
				cout << " ";
				//j++;
			}
		}


	}

	return 0;
}