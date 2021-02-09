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

char arr[51][51];
bool visited[51][51];

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int n, m;

bool Go(int x, int y, int px, int py, char color) {
	// from (px,py) we are now in (x,y)

	// we came back to visited place. Which means a cycle
	if (visited[x][y]) return true;

	// mark as visited.
	visited[x][y] = true;

	// 방향을 보면서.
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k]; int ny = y + dy[k];
		if (0 <= nx && nx < n && 0 <= ny && ny < m) { // 기본조건

			// 갈 곳이 (당연히) 같은 색상이고, 이전에 왔던 곳과 갈 곳이 같지 않다면.
			if (arr[nx][ny] == color && !(nx == px && ny == py))
				// 다음 단계를 진행. 데이터는 갱신됨.
				if (Go(nx, ny, x, y, color)) return true;
		}
	}
	return false;
}
int main() {

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			scanf("%1c", &arr[i][j]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j]) continue;
			bool Okay = Go(i, j, -1, -1, arr[i][j]);
			if (Okay) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
	return 0;
}