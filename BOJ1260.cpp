#pragma warning(disable:4996)
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int N, M, V;

bool a[1001][1001];
bool check[1001] = { false, };


void Dfs(int v) {
	check[v] = true;
	cout << v << ' ';
	for (int i = 1; i <= N; i++) {
		if (check[i] == false && a[v][i] == true) {
			Dfs(i);
		}
	}
}


void Bfs(int v) {
	//memset(check, false, sizeof(check));
	queue<int> q;
	check[v] = true; q.push(v);
	while (!q.empty()) {
		int x = q.front(); q.pop();
		printf("%d ", x);
		for (int i = 1; i <= N; i++) {
			if (check[i] == false && a[x][i] == true) {
				check[i] = true;
				q.push(i);
			}
		}
	}
}

int main() {
	cin >> N >> M >> V;
	int from, to;
	for (int i = 0; i < M; i++) {
		cin >> from >> to;
		a[from][to] = true;
		a[to][from] = true;
	}
	

	Dfs(V);
	printf("\n");
	for (int i = 0; i < 1001; i++) check[i] = false;
	Bfs(V);

	return 0;
}