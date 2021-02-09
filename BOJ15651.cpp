#pragma warning(disable:4996)
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;

int N, M;
bool visited[10] = { false, };
int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };

void Solve(int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++)
			printf("%d ", arr[i]);
	}
	for (int i = 1; i < N; i++) {
		if (visited[i]) continue;
		visited[i] = true; arr[cnt] = i;
		Solve(cnt + 1);
		visited[i] = false;
	}
}

int main() {
	scanf("%d %d", &N, &M);
	Solve(0);
}