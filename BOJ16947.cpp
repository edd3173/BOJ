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
// 하나도 모르겠네 ㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋ
int n;

int check[3001] = { -1, };
vector<int> arr[3001];
int dist[3001];

int Go(int x, int p) { // p에서 x로 왔음. y로 갈 거임.
	if (check[x] == 1) return x; // 사이클을 찾음
	check[x] = 1; // 방문
	for (int y : arr[x]) {
		if (y == p) continue; // 이전 정점과 같으면 스킵
		int res = Go(y, x); // 갱신.
		if (res == -2) return -2; // cycle을 찾았는데 포함되지 ㅏㅇㄶ음
		if (res >= 0) { // cycle찾음. 포함되지 않은 경우를 걸렀으니 이거는 찾은거임.
			check[x] = 2; // 방문했는데 사이클의 일부임
			if (x == res) return -2; // 어, 사이클이 시작된 지점이네? 그럼 앞으로의 리턴값은 -2가 되어야
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
			dist[i] = 0; // 순환점이다
			q.push(i);
		}
		else {
			dist[i] = -1; // -1이라 함은, 아직 방문하지 않은 것.
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