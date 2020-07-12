#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	int size;
	int n;
	cin >> size;
	int* arr = new int[size];
	stack<int> Stack;
	string str;

	for (int i = 0; i < size; i++)
		cin >> arr[i];

	int pos = 0;
	for (int i = 1; i <= size; i++) {
		Stack.push(i);
		str += '+';
		while (!Stack.empty() && Stack.top() == arr[pos]) {
			pos++;
			Stack.pop();
			str += '-';
		}
	} // 알고리즘의 핵심 : 쌓고, pop할만큼 pop. 다시 쌓을수 있을만큼 쌓음.

	if (!Stack.empty())
		cout << "NO" << endl;
	else
		cout << str << endl;

}