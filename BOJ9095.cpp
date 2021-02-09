#pragma warning(disable:4996)
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
int N;
int dp[11] = { 0, };
void DP() {
	dp[1] = 1; // 1 // 3을 더해서 4가 됨
	dp[2] = 2; // 1+1, 2 // 2를 더해서 4가 됨
	dp[3] = 4; // 1+1+1, 1+2, 2+1, 3 // 1을 더해서 4가 됨
	for (int i = 4; i < 11; i++) {
		// 어쨌든 dp[n]은 n-1에서 1을 더하던가, n-2에서 2를 더하던가, n-3에서 3을 더하던가
		// 세가지 경우의 수의 합.
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