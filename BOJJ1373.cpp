#include <iostream>
#include <math.h>
#include <string>
#include <stack>
using namespace std;

int main() {
	string s;
	stack<int> Stack; // to print result backward
	getline(cin, s); // get input
	if (s.length() % 3 != 0) {
		while(s.length()%3!=0)
			s.insert(0, "0");
	} // if not 3*n, attach zeros

	int first, second, third, res;
	//cout << s << endl;
	while (s.length() != 0) { // keep shifting

		third = s.back()-'0';
		s.pop_back();

		second = s.back()-'0';
		s.pop_back();

		first = s.back()-'0';
		s.pop_back();

		res = 4 * first + 2 * second + third;
		Stack.push(res);
	}

	while (!Stack.empty()) {
		int val = Stack.top();
		cout << val;
		Stack.pop();
	}

	return 0;
}