#pragma warning(disable:4996)
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;
#define MAX 100000

// okay
int n;
vector<int> V[MAX+1];
bool check[MAX + 1];
int parent[MAX + 1];


int depth[MAX + 1];
int dist[MAX + 1];


int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x, y;
		cin >> x >> y;
		V[x].push_back(y);
		V[y].push_back(x);
	}
	
	// �ʱⰪ.
	depth[1] = 0; check[1] = true;
	queue<int> q; q.push(1);

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int y = 0; y < V[x].size();y++) {
			if (!check[y]) {
				depth[y] = depth[x] + 1;
				check[y] = true;
				parent[y] = x;
				q.push(y);
			}
		}
	}

	for (int i = 2; i <= n; i++) {
		printf("%d\n", parent[i]);
	}
	return 0;
}