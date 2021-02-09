#pragma warning (disable : 4996)
#include <iostream>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <tuple>
using namespace std;

int n;
int cnt = 1;

int dist[1001][1001];
// dist[a][b] : (s,c)
int ans = -1;

void BFS() {
	// copy : (s,c) -> (s,s)
	// paste : (s,c) -> (s+c,c)
	// del : (s,c) -> (s-1,c)
	
	// init.
	for (int i = 0; i < 1001; i++) {
		for (int j = 0; j < 1001; j++)
			dist[i][j] = -1; // unvisited
	}

	// start with s=1
	queue<pair<int, int>> q;
	q.push(make_pair(1, 0));
	dist[1][0] = 0;

	// start BFS
	while (!q.empty()) {
		int s, c;
		pair<int, int> tmp = q.front();
		s = tmp.first; c = tmp.second;
		q.pop();

		// by branch

		// copy
		if (dist[s][c] == -1) {
			dist[s][s] = dist[s][c] + 1; // 1 sec pass
			q.push(make_pair(s, s)); // push
		}

		// paste
		if (s + c <= n && dist[s][c] == -1) {
			dist[s + c][c] = dist[s][c] + 1;
			q.push(make_pair(s + c, s));
		}

		// delete
		if (s - 1 >= 0 && dist[s - 1][c] == -1) {
			dist[s - 1][c] = dist[s][c] + 1;
			q.push(make_pair(s - 1, c));
		}

	}
	
	// �ּҰ� ã��. �̸�Ƽ���� s���̰�, Ŭ�����尡 �� ������ �𸣴ϱ�
	// Ŭ�������� �ּҸ� ã�´�.
	// �׷��� �ð��� �ּ�?? ������ �׷���??
	// �� �κ��� ���� ��ŭ;;;
	for (int i = 0; i <= n; i++) {
		if (dist[n][i] != -1) { // �湮�ߴ� ���̰�,
			if (ans > dist[n][i] || ans == -1)
				ans = dist[n][i];
		}
	}

}

int main() {
	cin >> n;
	BFS();
	cout << ans << endl;
}

