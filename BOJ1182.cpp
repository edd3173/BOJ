#pragma warning(disable:4996)
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int n, s;
int sum;
int cnt;

int main() {
	cin >> n >> s;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	int cnt = 0;
	for (int i = 1; i < (1 << n); i++) {
		sum = 0; // init.
		for (int k = 0; k < n; k++) {
			if (i & (1 << k)) // �� k��° �ڸ����� 1���� Ȯ���Ѵ�. (10111)�̸� v[0],v[2],v[3],v[4]�� pick�Ѱ�
				sum += v[k]; // ������
		}
		if (sum == s) // �޼�
			cnt++;
	}
	cout << cnt << endl;
}