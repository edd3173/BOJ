#pragma warning(disable:4996)
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool a[2000][2000]; // 인접행렬
vector<int> g[2000]; // 인접리스트
vector<pair<int, int>> edges; // 간선리스트



int main() {
	int n; int m;
	cin >> n >> m;
	
	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		edges.push_back({ from,to });
		edges.push_back({ to,from });
		a[from][to] = true; a[to][from] = true;
		g[from].push_back(to); g[to].push_back(from);
	}

	m = m * 2; // 친구 관계는 2배.
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			// A -> B
			int A = edges[i].first;
			int B = edges[i].second;

			// C->D
			int C = edges[j].first;
			int D = edges[j].first;

			if (A == B || A == C || A == D || B == C || B == D || C == D) continue;

			// check B->C
			if (!a[B][C]) continue;

			// D->E
			for (int E : g[D]) {
				if (E == A || E == B || E == C || E == D) continue;
				cout << 1 << endl;
				return 0;
			}
		}
	}

	cout << 0 << endl;

	return 0;
}