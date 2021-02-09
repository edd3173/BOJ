#pragma warning(disable:4996)
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
int N;
int dp[11] = { 0, };
void DP() {
	dp[1] = 1; // 1 // 3�� ���ؼ� 4�� ��
	dp[2] = 2; // 1+1, 2 // 2�� ���ؼ� 4�� ��
	dp[3] = 4; // 1+1+1, 1+2, 2+1, 3 // 1�� ���ؼ� 4�� ��
	for (int i = 4; i < 11; i++) {
		// ��·�� dp[n]�� n-1���� 1�� ���ϴ���, n-2���� 2�� ���ϴ���, n-3���� 3�� ���ϴ���
		// ������ ����� ���� ��.
		dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
	}
}
int main() {
	int tc = 0;
	scanf("%d", &tc);
	DP();
	for (int i = 0; i < tc; i++) {
		scanf("%d", &N);
		printf("%d\n", dp[N]);
	}
	return 0;
}