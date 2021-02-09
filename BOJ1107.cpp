#pragma warning(disable:4996)
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>

using namespace std;
bool broken[10] = { false, };

// check if channel is reachable
bool isPossible(int num) {
	int i = 0, res = 0;
	string target = to_string(num);

	for (i = 0; i < target.length(); i++) {
		if (broken[target[i] - '0'] == true) {
			return false;
		}
	}
	return true;
}

int Digit(int num) { // return number of press to reach channel
	int i = 0, res = 0;
	string target = to_string(num);
	return target.length();
}

int main() {
	int n, m;
	int i, j;
	int tmp;

	scanf("%d", &n);
	scanf("%d", &m);
	for (i = 0; i < m; i++) {
		scanf("%d", &tmp);
		broken[tmp] = true;
	}
	// case 1 : only using +-
	int ans = n - 100;
	if (ans < 0)
		ans = -ans;

	// case 2 : choose closest channel, and use +-
	// key is to find closest number, with brute force
	// no special algorithm is needed

	for (i = 0; i < 1000000; i++) { // like this
		int cur = i; // current number
		int dig = Digit(cur); // number of press to reach current number
		if (isPossible(i)) { // if current number is reachable
			int addition = cur - n; // additional press need to reach target
			if (addition < 0) addition = -addition; // for abs.
			// dig+addition means, closest number + additional press
			if (ans > dig + addition) // if current ans is bigger,
				ans = dig + addition; // change to smaller
		}
	}

	printf("%d\n", ans);
}

