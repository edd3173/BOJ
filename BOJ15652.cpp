#pragma warning(disable:4996)
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;

bool c[10]; int a[10];
void Go(int idx, int start, int n, int m) {
	if (idx == m) {
		// print
		return;
	}
	for (int i = start; i <= n; i++) {
		a[idx] = i;
		Go(idx + 1, i, n, m);
		// idx level up, and start position is also level uped, but not i+1. NOT strictly bigger.
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	Go(0, 1, n, m);
}