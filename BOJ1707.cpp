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

int k, v, e;

vector<int> V[20001];
int color[20001] = { 0, };

void DFS(int start, int c) {
	color[start] = c;
	for (int i = 0; i < V[start].size(); i++) {
		int next = V[start][i];
		if (color[next] == 0) // non-visited
			DFS(next, 3 - c); // if cur, 1, color next with 2. If cur 2, color next with 1
	}
}

void Solve() {
	for (int j = 1; j <= e; j++) {
		if (color[j] == 0)
			DFS(j, 1);
	}
	bool okay = true;
	for (int i = 1; i <= e; i++) {
		for (int k = 0; k < V[i].size(); k++) {
			int j = V[i][k];
			if (color[i] == color[j]) okay = false; 
			/*
			color[i] : i-th vertice의 color
			color[j] : i-th vertice와 연결되있는 다른 vertice들의 color
			이 둘의 color(adj vertice)의 color가 서로 달라야 함.
			*/
		}
	}
	if (okay)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}


int main() {
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> v >> e;
		for (int j = 0; j < e; j++) {
			int from, to;
			cin >> from >> to;
			V[from].push_back(to);
			V[to].push_back(from);
		}
		Solve();
	}
	return 0;
}
