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

int arr[101][101];
int visited[101][101];
int dist[101][101]; // 핵심!!

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void BFS(int x, int y) { // 0,0부터 돌릴거임
	
	// 초기값
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	visited[x][y] = 1; dist[x][y] = 1; 
	
	// 시작
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		// 다음 방향으로 움직이기 전에 check
		if (x == n - 1 && y == m - 1) {
			cout << dist[x][y] << endl;
			break;
		} // 출력 후 종료. DFS가 아니니까 가능.

		//상하좌우 찾는다.
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (arr[nx][ny] == 1 && visited[nx][ny] == 0) {
					q.push(make_pair(nx, ny));
					dist[nx][ny] = dist[x][y] + 1;
					visited[nx][ny] = 1;
				}
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			scanf("%1d", &arr[i][j]);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			visited[i][j] = 0;
	}

	BFS(0, 0);
	// 그냥 0부터 돌리면 됨. 굳이 이중 루프 안에서 돌릴 필요 없음.
}