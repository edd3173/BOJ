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
#include <deque>
using namespace std;

int m, n;

int arr[555][555];
int dist[555][555];

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };


// ��ĭ���� �̵��� ����ġ 0, ���� �ν��� ����ġ 1
// ����ġ�� 1�� �κ��� �ڿ�, �� �մ� �κп��� �տ�.
// ��ġ �� �������� 0�� ���� ť, 1�� ���� ť�� �ߵ���.
void BFS() {
	deque<pair<int, int>> deq;
	deq.push_back(make_pair(0, 0));
	dist[0][0] = 0;

	while (!deq.empty()) {
		int x = deq.front().first;
		int y = deq.front().second;
		deq.pop_front();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (dist[nx][ny] == -1) { // unvisited
					if (arr[nx][ny] == 0) { // �� ����, ����ġ 0
						deq.push_front(make_pair(nx, ny)); // �տ� ����
						dist[nx][ny] = dist[x][y];
					}
					else { // �� ����. ����ġ 1
						deq.push_back(make_pair(nx, ny)); // �ڿ� ����.
						dist[nx][ny] = dist[x][y] + 1;
					}
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
			dist[i][j] = -1;
		}
	}
	BFS();
	cout << dist[n - 1][m - 1] << endl;
	
	return 0;
}