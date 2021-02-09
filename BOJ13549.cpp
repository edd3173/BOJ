#pragma warning (disable : 4996)
#include <iostream>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <tuple>
using namespace std;

#define MAX 100000
int n, k;


bool check[MAX+1] = { false, };
int dist[MAX + 1];

void BFS() {
	queue<int> curQ;
	queue<int> nextQ;
	curQ.push(n); check[n] = true; dist[n] = 0;

	while (!curQ.empty()) {
		int now = curQ.front(); curQ.pop();
		if (now * 2 < MAX) { // 0 ���� ���� ���� ť�� �ְ�
			if (check[now * 2] == false) {
				curQ.push(now * 2);
				check[now * 2] = true;
				dist[now * 2] = dist[now];
			}
		}
		if (now - 1 >= 0) { // 1�ʰ� �ɸ� ������ ���� ť�� �ִ´�.
			if (check[now - 1] == false) {
				nextQ.push(now - 1);
				check[now - 1] = true;
				dist[now - 1] = dist[now] + 1;
			}
		}
		if (now + 1 < MAX) {
			if (check[now + 1] == false) {
				nextQ.push(now + 1);
				check[now + 1] = true;
				dist[now + 1] = dist[now] + 1;
			}
		}
		if (curQ.empty()) { // ���� ť�� �� ������. �� *2�� ��츦 �� ��������(0��) ���� +-�� �Ѿ.
			curQ = nextQ;
			nextQ = queue<int>();
		}
	}
}

int main() {
	cin >> n >> k;
	BFS();
	cout << dist[k] << endl;
	return 0;
}