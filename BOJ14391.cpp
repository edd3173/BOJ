#pragma warning(disable:4996)
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
int a[4][4];

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	}
	int ans = 0;
	// 0 : -, 1 : |

	// s의 크기가 pow(2,nm)
	for (int s = 0; s < (1 << (n * m)); s++) {
		int sum = 0;
		for (int i = 0; i < n; i++) { // 가로 1개.
			int cur = 0; // 누적된 (가로) 수
			for (int j = 0; j < m; j++) { 
				int k = i * m + j; // index of row major.
				if ((s & (1 << k)) == 0) // vertical
					cur = cur * 10 + a[i][j]; // 123,4 become 1234
				else { // horizontal
					sum += cur;
					cur = 0;
				}
			}
			sum += cur;  // 가로로 끝나면, 그것을 더해줘야됨.
		}
		
		for (int j = 0; j < m; j++) {
			int cur = 0;
			for (int i = 0; i < n; i++) {
				int k = i * m + j;
				if ((s & (1 << k)) != 0)
					cur = cur * 10 + a[i][j];
				else {
					sum += cur;
					cur = 0;
				}
			}
			sum += cur;
		}
		ans = max(ans, sum);
	}

	cout << ans << endl;

	return 0;
}