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
int n;

int arr[30][30];
int group[30][30];
int cnt = 0;
int ans[26 * 26];

// for X and Y movement
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void BFS(int i, int j, int cnt) {
	// visited�� arr������ �̹� �ɷ����ϱ� �׳� �����ϸ��.
	queue<pair<int, int>> q;
	q.push(make_pair(i, j)); group[i][j] = cnt;
	// group�� cnt �ֱ� ����. ������ ��Ÿ���Ե�.

	while (!q.empty()) {
		// ����.
		i = q.front().first; j = q.front().second; q.pop();
		// x,y�� movement�ε�, �¿���Ϸθ� �����̸� �ᱹ �� Ŀ���� �� ����.
		for (int k = 0; k < 4; k++) {
			// ���� �̷��� �Ѵ�.
			int nx = i + dx[k];
			int ny = j + dy[k]; 

			// �ٿ���� üũ
			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				// ��ȿ�ϰ�, unvisited���� 
				if (arr[nx][ny] == 1 && group[nx][ny] == 0) {
					q.push(make_pair(nx, ny));
					group[nx][ny] = cnt;
				}
			}
		}
	}
}

void DFS(int x, int y, int cnt) {
	group[x][y] = cnt;
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (0 <= nx && nx < n && 0 <= ny && ny < n) {
			if (arr[nx][ny] == 1 && group[nx][ny] == 0)
				DFS(nx, ny, cnt);
		}
	}
}


int main() {

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			scanf("%1d", &arr[i][j]); // �߿�! �츮�� input�� int���� ������
		// computer�� 10111�� 5���� ��������, 1���� �������� �𸥴�!
		// ���� %1d�� ���ִ°��� ����
	}

	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 26; j++)
			group[i][j] = 0;
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			// ���� ������. ���ǹ��� �迭, �׸��� not visited.
			if (arr[i][j] == 1 && group[i][j] == 0)
				BFS(i, j, ++cnt); // group�� 1�̻��̶�°� visited�� �ǹ�.
				//DFS(i, j, ++cnt);
		}
	}

	cout << cnt << endl;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			ans[group[i][j]]++;
	}

	sort(ans + 1, ans + cnt + 1); // ������ 1���ʹϱ� ans+1, 
	// ������ �� cnt, ans�� ���� ������ group�� ������ ����.
	for (int i = 1; i <= cnt; i++) {
		cout << ans[i] << endl;
	}


	return 0;
}