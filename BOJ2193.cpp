#include <iostream>
using namespace std;

int main() {
	/*
	N=1
	1 dp[1][0]=0
	  dp[1][1]=1

	N=2
	10 dp[2][0]=1
		dp[2][1]=0

	N=3
	100 
	101 
	// dp[3][0]=dp[2][0]+dp[2][1]
		dp[3][1]=dp[3][0]

	N=4
	1000
	1001

	1010
	// dp[4][0]=dp[3][0]+dp[3][1]
	// dp[4][1]=dp[3][0]

	N=5
	10001
	10000
	
	10010

	10100
	10101

	// dp[5][0]=dp[4][0]+dp[4][1]
	// dp[5][1]=dp[4][0]
	*/

	int n;
	cin >> n;

	long long dp[91][2] = { 0, };
	dp[1][0] = 0;
	dp[1][1] = 1;
	dp[2][1] = 0;
	dp[2][0] = 1;

	for (int i = 3; i <= n; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
	}

	cout << dp[n][0] + dp[n][1] << endl;
}