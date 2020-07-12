#include <math.h>
#include <iostream>
using namespace std;

int GCD(int x, int y) {
	if (y == 0)
		return x;
	return GCD(y, x%y);
}

int main() {
	int n, s;
	int ans;
	cin >> n >> s;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < n; i++)
		arr[i] = abs(s - arr[i]);

	ans = arr[0];
	for (int i = 0; i < n; i++){
		ans = GCD(ans, arr[i]);
	}
	cout << ans;
	return 0;
}