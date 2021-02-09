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
	while (i > 0 && a[i] <= a[i - 1]) { // ������ part�� ���Ҽ����� ã��
		i--;
	}
	if (i <= 0) {
		printf("-1\n");
		return false;
	} // ���ΰ� ���Ҽ����̶�� false

	int j = N - 1;
	while (a[j] <= a[i - 1]) {
		j--;
	} // j�� idx�� ã��. ���⼭ j�� ���Ҽ��� �� a[i-1]���� ū ���� ���� ��.

	swap(a[i - 1], a[j]); // ����

	j = N - 1; // endpoint
	while (i < j) {
		swap(a[i], a[j]);
		i++; j--;
	} // ���� ���Ҽ����� �������ش�.

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