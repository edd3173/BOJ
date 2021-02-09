#pragma warning(disable:4996)
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int N;

int getSum(vector<int>& a) {
	int sum = 0;
	for (int i = 0; i < N-1; i++) {
		sum += abs(a[i] - a[i + 1]);
	}
	return sum;
}
int main() {
	cin >> N;
	vector<int> a(N);
	int Max = 0;
	for (int i = 0; i < N; i++) {
		a[i] = i + 1;
	}
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());

	do {
		int cur = getSum(a);
		Max = max(Max, cur);
	} while (next_permutation(a.begin(), a.end()));
	cout << Max << endl;
	return 0;
}