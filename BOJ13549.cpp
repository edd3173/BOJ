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
		if (now * 2 < MAX) { // 0 초일 때는 현재 큐에 넣고
			if (check[now * 2] == false) {
				curQ.push(now * 2);
				check[now * 2] = true;
				dist[now * 2] = dist[now];
			}
		}
		if (now - 1 >= 0) { // 1초가 걸릴 때에는 다음 큐에 넣는다.
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
		if (curQ.empty()) { // 현재 큐를 다 보았음. 즉 *2배 경우를 다 보았으니(0초) 이제 +-로 넘어감.
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