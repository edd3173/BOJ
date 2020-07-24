#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	int arr[1001] = { 0, };
	int dp[1001];
	int res = 1;
	for (int i = 0; i < 1001; i++)
		dp[i] = 1;
	
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	for (int i = 2; i <= n; i++) {
		for (int j = i-1; j >= 1; j--) {
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[i],dp[j] + 1);
			}
		}
		res = max(res, dp[i]); // 이런식으로 구하네. 신기했다.
	}


	cout << res << endl;
	

	return 0;
}