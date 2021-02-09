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

int tc, l;
int srcX; int srcY; int dstX; int dstY;
int arr[301][301];
int dist[301][301]; // vist과 거의 비슷함. graph coloring

int dx[] = { -2,-1,1,2,2,1,-1,-2 };
int dy[] = { 1,2,2,1,-1,-2,-2,-1 };

void BFS() {
	queue<pair<int, int>> q;
	q.push(make_pair(srcX, srcY));
	dist[srcX][srcY] = 0;

	while (!q.empty()) {
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();
		if (curX == dstX && curY == dstY) { // 목적지
			cout << dist[curX][curY] << endl;  // 출력
			break; // 종료
		}
		for (int k = 0; k < 8; k++) {
			int nx = curX + dx[k]; int ny = curY + dy[k];
			if (0 <= nx && nx < l && 0 <= ny && ny < l) {
				if (dist[nx][ny] == -1) {
					dist[nx][ny] = dist[curX][curY] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}


int main() {
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		cin >> l;

		for (int k = 0; k < l; k++) {
			for (int j = 0; j < l; j++)
				dist[k][j] = -1;
		}
		
		cin >> srcX >> srcY;
		cin >> dstX >> dstY;

		BFS(); // 인자 안넣는게 깔끔한거 같기는 해..
	}
}