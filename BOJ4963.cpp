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

int w, h;

int arr[51][51];
int visited[51][51];
int cnt = 0;

int dx[8] = { 0,0,-1,1,1,1,-1,-1 };
int dy[8] = { 1,-1,0,0,1,-1,1,-1 };

void BFS(int x, int y, int cnt) {
	queue<pair<int,int>> q;
	q.push(make_pair(x, y)); visited[x][y] = cnt;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int k = 0; k < 8; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (0 <= nx && nx < h && 0 <= ny && ny < w) {
				if (arr[nx][ny] == 1 && visited[nx][ny] == 0) {
					q.push(make_pair(nx, ny));
					visited[nx][ny] = cnt;
				}
			}
		}
	}
}


int main() {
	while (true) {
		cin >> w >> h;
		if (w == 0 && h == 0)
			exit(0);

		// init.
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++)
				arr[i][j] = 0;
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++)
				visited[i][j] = 0;
		}

		cnt = 0;

		// scanf
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++)
				scanf("%1d", &arr[i][j]);
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (arr[i][j] == 1 && visited[i][j]==0)
					BFS(i, j, ++cnt);
			}
		}

		cout << cnt << endl;

	}
}