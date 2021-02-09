#pragma warning(disable:4996) 
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	vector<int> h;
	int i = 0, j = 0;
	int tmp = 0; int total = 0;
	for (i = 0; i < 9; i++) {
		cin >> tmp;
		h.push_back(tmp);
		total += tmp;
	}

	int target = total - 100;
	sort(h.begin(), h.end());

	for (i = 0; i < 8; i++) {
		for (j = i + 1; j < 9; j++) {
			if (h[i] + h[j] == target) {
				for(int k = 0; k < 9; k++){
					if (k == i || k == j) continue;
					cout << h[k] << '\n';
				}
				return 0;
			}
		}
	}
}