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

#define MAX 200000

int n, k;
bool check[MAX + 1] = { false, };
int dist[MAX + 1] = { 0, };
int from[MAX + 1] = { -1, };

void BFS() {
	queue<int> q;
	check[n] = true; dist[n] = 0; q.push(n);
	
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		if (now - 1 >= 0) {
			if (check[now - 1] == false) {
				check[now - 1] = true;
				q.push(now - 1);
				dist[now - 1] = dist[now] + 1;
				from[now - 1] = now;
			}
		}
		if (now + 1 < MAX) {
			if (check[now + 1] == false) {
				q.push(now + 1);
				check[now + 1] = true;
				dist[now + 1] = dist[now] + 1;
				from[now + 1] = now;
			}
		}
		if (now * 2 < MAX) {
			if (check[now * 2] == false) {
				q.push(now * 2);
				check[now * 2] = true;
				dist[now * 2] = dist[now] + 1;
				from[now * 2] = now;
			}
		}
	}
}


int main() {
	cin >> n >> k;
	BFS();
	cout << dist[k] << endl;
	stack<int> s;

	int cur = k;
	while (true) {
		// 경로 추적을 위해서, 스택에 지나온 경로를 push한다.
		s.push(cur);
		//cout << cur << ' ';
		if (cur == n) break; // 시작점. 따라서 탈출.
		cur = from[cur];
	}

	// 그리고 출력
	while (!s.empty()) {
		int cur = s.top();
		cout << cur << ' ';
		s.pop();
	}
}