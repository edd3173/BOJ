#pragma warning(disable:4996)
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int N;
int arr[10][10];
vector<int> visit(10);
void Solve() {
	int ans = 0;
	do {
		// if (visit[0] != 1) break;
		bool okay = true;
		int sum = 0;
		for (int i = 0; i < N - 1; i++) {
			if (arr[visit[i]][visit[i + 1]] == 0) okay = false;
			else
				sum += arr[visit[i]][visit[i + 1]];
			if (okay && arr[visit[N - 1]][0] != 0) {
				sum += arr[visit[N - 1]][0];
				if (ans > sum) ans = sum;
			}
		}
	} while (next_permutation(visit.begin(), visit.end()));
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
	}
	Solve();
}