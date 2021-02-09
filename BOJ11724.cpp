#pragma warning(disable:4996)
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int n, m;
vector<int> v[1001];
bool check[1001] = { false, };

void DFS(int start) { // CODE
	check[start] = true; // Okay

	for (int i = 0; i < v[start].size(); i++) { // FROM 0!! NOT 1.
		int next = v[start][i]; // okay
		if (!check[next]) // okay
			DFS(next);
	}
}


int Solve() {
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (!check[i]) {
			DFS(i);
			cnt++;
		}
	}
	return cnt;
}

int main() {
	cin >> n >> m;
	int from, to;
	for (int i = 0; i < m; i++) {
		cin >> from >> to;
		v[from].push_back(to);
		v[to].push_back(from);
	}
	cout << Solve() << endl;
}