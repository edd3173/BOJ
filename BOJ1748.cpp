#pragma warning(disable:4996)
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;
int N;

int getLen(int n) {
	string tmp = to_string(n);
	return tmp.length();
}

int main() {
	scanf("%d", &N);
	long add = 0;
	long base = 0;
	long total = 0;
	int digit = getLen(N);
	if (digit == 1) {
		base = 1;
		add = N - 1;
		total = base + add;
	}
	else if (digit == 2) {
		base = 9; // total of case 1
		add = 2 * (N - 9);
		total = base + add;
	}
	else if (digit == 3) {
		base = 9 + 2 * 90;
		add = 3 * (N - 99);
		total = base + add;
	}
	else if (digit == 4) {
		base = 9 + 2 * 90 + 3 * 900;
		add = 4 * (N - 999);
		total = base + add;
	}
	else if (digit == 5) {
		base = 9 + 2 * 90 + 3 * 900 + 4 * 9000;
		add = 5 * (N - 9999);
		total = base + add;
	}
	else if (digit == 6) {
		base = 9 + 2 * 90 + 3 * 900 + 4 * 9000 + 5 * 90000;
		add = 6 * (N - 99999);
		total = base + add;
	}
	else if (digit == 7) {
		base = 9 + 2 * 90 + 3 * 900 + 4 * 9000 + 5 * 90000 + 6 * 900000;
		add = 7 * (N - 999999);
		total = base + add;
	}
	else if (digit == 8) {
		base = 9 + 2 * 90 + 3 * 900 + 4 * 9000 + 5 * 90000 + 6 * 900000 + 7 * 9000000;
		add = 8 * (N - 9999999);
		total = base + add;
	}
	else if (digit == 9) {
		base = 9 + 2 * 90 + 3 * 900 + 4 * 9000 + 5 * 90000 + 6 * 900000 + 7 * 9000000 + 8 * 90000000;
		add = 9;
		total = base + add;
	}
	printf("%d\n", total);
	return 0;
}