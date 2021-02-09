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

int n, m, v;
vector<int> V[1001];
bool check[1001] = { false, };

void BFS(int start) {
	// init.
	memset(check, false, sizeof(check));
	// make queue
	queue<int> q;
	
	//start
	q.push(start); check[start] = true;
	
	//while
	while (!q.empty()) {
		int now = q.front();
		q.pop(); 
		printf("%d ", now);

		for (int i = 0; i < (int)V[now].size(); i++) { // search through current list
			int next = V[now][i]; // we found target
			if (!check[next]) { // if unchecked
				check[next] = true; // check
				q.push(next); // push
			}
		}
	}
}

void DFS(int start) {
	check[start] = true;
	printf("%d ", start);
	for (int i = 0; i < (int)V[start].size(); i++) {
		int next = V[start][i];
		if (!check[next]) DFS(next);
	}
}

int main() {
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		V[from].push_back(to);
		V[to].push_back(from);
	}
	for (int i = 1; i <= n; i++)
		sort(V[i].begin(), V[i].end());
	
	DFS(v);
	printf("\n");
	BFS(v);

}