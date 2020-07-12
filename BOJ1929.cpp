#include <iostream>
#include <cstdio>
#include <stdbool.h>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	bool* arr = new bool[b + 1];

	for (int i = 0; i <=b ; i++)
		arr[i] = true;

	for (int i = 2; i <= b; i++) {
		if (arr[i]) { // unchecked
			for (int j = i * i; j <= b; j += i)
				arr[j] = false;
		}
	}

	for (int i = a; i <= b; i++)
		if (arr[i])
			cout << i << ' ';

	return 0;
}