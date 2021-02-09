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
	while (!q.empty()) { // 1�� ������κ��� ��� dfs�� ������.
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
			dist[i][j] = -1; // �⺻���� -1. ������ �� ���� �����̴�.
			if (arr[i][j] == 1) {
				q.push(make_pair(i, j)); // ���������̹Ƿ� push
				dist[i][j] = 0; // ���Ⱑ ������
			}
		}
	}
	BFS(); // ����

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (ans <= dist[i][j])
				ans = dist[i][j]; // �ִ�Ÿ� ����
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dist[i][j] == -1 && arr[i][j] == 0) // BFS�� �ߴµ�, ���� ���� tomato�� ����.
				// ��, dfs�� �������� �������Ƿ� ������ dis[i][j]==-1�̴�.
				// ����, arr[i][j]==0���� ���� ���� tomato�� �ִ�.
				ans = -1;
		}
	}

	cout << ans << endl;
}