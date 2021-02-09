#pragma warning(disable:4996)
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>

void Solve(int M, int N, int x, int y) {
	// -1 �� ���ָ�, %�������� �츮�� <x,y>�� table�� ������ �ִ� �Ͱ� ��������
	// ���? <x,y> = <i%M, i%N> -> ����� ��.
	x -= 1; y -= 1;

	bool isValid = false;
	for (int i = x; i < N * M; i += M) {
		if (i % N == y) {
			isValid = true;
			printf("%d\n", i + 1);
			break;
		}
	}
	if (!isValid)
		printf("-1\n");
}

int main() {
	int tc = 0;
	int i, j;
	int M, N, x, y;
	scanf("%d", &tc);
	for (i = 0; i < tc; i++) {
		scanf("%d %d %d %d", &M, &N, &x, &y);
		Solve(M, N, x, y);
	}
}