#pragma warning(disable:4996)
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;

int N;

bool NextPerm(int* a) {
	int i = N - 1;
	while (i > 0 && a[i] <= a[i - 1]) { // 순열의 part중 감소순열을 찾음
		i--;
	}
	if (i <= 0) {
		printf("-1\n");
		return false;
	} // 전부가 감소순열이라면 false

	int j = N - 1;
	while (a[j] <= a[i - 1]) {
		j--;
	} // j의 idx를 찾음. 여기서 j는 감소순열 중 a[i-1]보다 큰 가장 작은 수.

	swap(a[i - 1], a[j]); // 스왑

	j = N - 1; // endpoint
	while (i < j) {
		swap(a[i], a[j]);
		i++; j--;
	} // 이제 감소순열을 뒤집어준다.

	for (i = 0; i < N; i++)
		printf("%d ", a[i]);

	return true;
}

int main() {
	cin >> N;
	int* arr = new int[N];
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	NextPerm(arr);

	return 0;
}