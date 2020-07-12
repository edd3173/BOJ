#include <iostream>
#include <math.h>
using namespace std;

int getNum(int n) {
	int cur = n;
	int cnt = 0;
	while (cur > 0) {
		cnt += cur / 5;
		cur /= 5;
	}

	return cnt;
}

int main() {
	int n;
	//cout << "Input n > ";
	cin >> n;
	
	cout << getNum(n) << endl;

	return 0;
}