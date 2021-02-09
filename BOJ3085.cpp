#include <iostream>
#include <cstdio>
#include <cstdlib>
#pragma warning(disable:4996)

using namespace std;
int n;
char arr[51][51];

int Solve() {
	int ans = 1;
	int i = 0, j = 0;
	int cur = 0;

	// check horizon
	for (i = 0; i < n; i++) {
		cur = 1;
		for (j = 1; j < n; j++) {
			if (arr[i][j] == arr[i][j - 1])
				cur++;
			else {
				ans = max(ans, cur);
				cur = 1;
			}
		}
		ans = max(ans, cur);
	}

	// check vertical
	for (i = 0; i < n; i++) {
		cur = 1;
		for (j = 0; j < n - 1; j++) {
			if (arr[j][i] == arr[j + 1][i]) {
				cur++;
			}
			else {
				ans = max(ans, cur);
				cur = 1;
			}
		}
		ans = max(ans, cur);
	}

	return ans;
}

int main() {

	scanf("%d", &n);

	int i = 0, j = 0;
	
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++) 
			scanf("%c", &arr[i][j]);

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}


	int res = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n - 1; j++) {
			// swap horizon
			swap(arr[i][j], arr[i][j + 1]);
			res = max(res, Solve());
			swap(arr[i][j], arr[i][j + 1]);

			// swap vertical
			swap(arr[j + 1][i], arr[j][i]);
			res = max(res, Solve());
			swap(arr[j + 1][i], arr[j][i]);
		}
	}
	
	cout << res << '\n';
}