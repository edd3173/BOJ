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

// for maximum limit
#define MAX 200000
int n, k;

// follows maximum
bool check[200001] = { false, };
int dist[200001];


void BFS() {
	// first case 
	queue<int> q;
	check[n] = true; dist[n] = 0;
	q.push(n);

	// do BFS 
	while (!q.empty()) {
		// okay
		int now = q.front();
		q.pop();

		// find next point

		// branch. -1
		if (now - 1 >= 0) {
			if (check[now - 1] == false) {
				q.push(now - 1);
				check[now - 1] = true;
				dist[now - 1] = dist[now] + 1;
			}
		}
		// branch. +1
		if (now + 1 < MAX) {
			if (check[now + 1] == false) {
				q.push(now + 1);
				check[now + 1] = true;
				dist[now + 1] = dist[now] + 1;
			}
		}
		// branch. double
		if (now * 2 < MAX) {
			if (check[2 * now] == false) {
				q.push(now * 2);
				check[now * 2] = true;
				dist[now * 2] = dist[now] + 1;
			}
		}
	}
}

int main() {
	cin >> n >> k;
	BFS();
	cout << dist[k] << endl;
}