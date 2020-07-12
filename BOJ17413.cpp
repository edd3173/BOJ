#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	string buf;
	char tmp;
	stack<char> Stack;
	bool tagFlag = false;
	getline(cin, buf);
	for (int i = 0; i < buf.size(); i++) {
		if (buf[i] == '<' || buf[i]=='>' ) {
			if (buf[i] == '<') {
				while (!Stack.empty()) {
					tmp = Stack.top();
					cout << tmp;
					Stack.pop();
				} // stack must be popped.

				tagFlag = true;
				cout << buf[i];
			}
			if (buf[i] == '>') {
				tagFlag = false;
				cout << buf[i];
			}
		}
		else { // normal characters
			if (tagFlag == true) { // inside tag
				//just print
				cout << buf[i];
			}
			else { // outside tag
				// push in stack
				if (buf[i] != ' ') {
					Stack.push(buf[i]);
				}
				if (buf[i] == ' ' || i==buf.length()-1) {
					while (!Stack.empty()) {
						tmp = Stack.top();
						cout << tmp;
						Stack.pop();
					}
					cout << ' ';
				}
			}
		}
	}
}