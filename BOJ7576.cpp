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

int m, n;

int arr[1001][1001];
int dist[1001][1001];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

queue<pair<int,int>> q;

void BFS() {
	while (!q.empty()) { // 1인 지점들로부터 모두 dfs를 돌린다.
		int x = q.front().first; int y = q.front().second; q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (arr[nx][ny] == 0 && dist[nx][ny] == -1) {
					dist[nx][ny] = dist[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}


int main() {
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &arr[i][j]);
			dist[i][j] = -1; // 기본값은 -1. 시작할 수 없는 지점이다.
			if (arr[i][j] == 1) {
				q.push(make_pair(i, j)); // 시작지점이므로 push
				dist[i][j] = 0; // 여기가 시작점
			}
		}
	}
	BFS(); // 시작

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (ans <= dist[i][j])
				ans = dist[i][j]; // 최대거리 구함
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dist[i][j] == -1 && arr[i][j] == 0) // BFS를 했는데, 익지 않은 tomato가 있음.
				// 즉, dfs로 도달하지 못했으므로 여전히 dis[i][j]==-1이다.
				// 또한, arr[i][j]==0임은 익지 않은 tomato가 있다.
				ans = -1;
		}
	}

	cout << ans << endl;
}