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
// �ϳ��� �𸣰ڳ� ����������������������
int n;

int check[3001] = { -1, };
vector<int> arr[3001];
int dist[3001];

int Go(int x, int p) { // p���� x�� ����. y�� �� ����.
	if (check[x] == 1) return x; // ����Ŭ�� ã��
	check[x] = 1; // �湮
	for (int y : arr[x]) {
		if (y == p) continue; // ���� ������ ������ ��ŵ
		int res = Go(y, x); // ����.
		if (res == -2) return -2; // cycle�� ã�Ҵµ� ���Ե��� ��������
		if (res >= 0) { // cycleã��. ���Ե��� ���� ��츦 �ɷ����� �̰Ŵ� ã������.
			check[x] = 2; // �湮�ߴµ� ����Ŭ�� �Ϻ���
			if (x == res) return -2; // ��, ����Ŭ�� ���۵� �����̳�? �׷� �������� ���ϰ��� -2�� �Ǿ��
			else return res;
		}
	}
	return -1;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u -= 1; v -= 1;
		arr[u].push_back(v);
		arr[v].push_back(u);
	}
	Go(0, -1);

	queue<int> q;
	for (int i = 0; i < n; i++) {
		if (check[i] == 2) {
			dist[i] = 0; // ��ȯ���̴�
			q.push(i);
		}
		else {
			dist[i] = -1; // -1�̶� ����, ���� �湮���� ���� ��.
		}
	}

	//BFS 
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int y : arr[x]) {
			if (dist[y] == -1) {
				q.push(y);
				dist[y] = dist[x] + 1;
			}
		}
	}

	for (int i = 0; i < n; i++)
		cout << dist[i] << ' ';
	cout << endl;
	return 0;

}