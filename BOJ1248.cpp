#pragma warning(disable:4996)
#include <utility>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int n;
char a[10][10];
vector<int> v;

bool Possible(int idx) { // �־��� ��ȣ�� �´��� Ȯ���Ѵ�.
	int sum = 0; // curSum
	for (int i = idx; i >= 0; i--) {
		sum += v[i]; // a[i][idx]�� sum�� ���� ��ȣ�� �� �ۿ� ����. ǥ check. ��Ƴ�.
		if (a[i][idx] == '+' && sum <= 0) return false;
		if (a[i][idx] == '0' && sum != 0) return false;
		if (a[i][idx] == '-' && sum >= 0) return false;
	}
	return true;
}

void Solve(int idx) {
	if (idx == n) { // we found 
		for (auto k : v)
			cout << k;
		cout << '\n';
		exit(0);
	}
	for (int i = -10; i <= 10; i++) {
		v.push_back(i);
		if (Possible(idx)) Solve(idx + 1);
		v.pop_back();
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++)
			cin >> a[i][j];
	}
	Solve(0);
	return 0;
}