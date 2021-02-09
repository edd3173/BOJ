#include <iostream>
#include <string>
using namespace std;
int n;
int sign[10][10];
int ans[10];

bool Ok() {
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = i; j < n; j++) {
			sum += ans[j];
			if (sign[i][j] == 0) {
				if (sum != 0) return false;
			}
			else if (sign[i][j] > 0) {
				if (sum <= 0) return false;
			}
			else if (sign[i][j] < 0) {
				if (sum >= 0) return false;
			}
		}
	}
	return true;
}

bool Go(int idx) {
	if (idx == n)
		return Ok();
	for (int i = -10; i <= 10; i++) {
		ans[idx] = i;
		if (Go(idx + 1)) return true;
	}
	return false;
}

int main() {
	cin >> n;
	string s;
	cin >> s;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (s[cnt] == '0')
				sign[i][j] = 0;
			else if (s[cnt] == '+')
				sign[i][j] = 1;
			else
				sign[i][j] = -1;
			cnt++;
		}
	}
	Go(0);
	for (int i = 0; i < n; i++)
		cout << ans[i] << ' ';
	cout << endl;
	return 0;
}