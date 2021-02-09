#pragma warning(disable:4996)
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int T[15]; int P[15];
int ans = 0;

void Go(int day, int sum) {
	// found
	if (day == N + 1) {
		if (ans < sum) ans = sum;
		return;
	}
	// impossible
	if (day > N + 1) {
		return;
	}
	// pick
	Go(day + T[day], sum + P[day]);
	Go(day + 1, sum);
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> T[i] >> P[i];
	}
	Go(1, 0);
	cout << ans << endl;
	return 0;
}