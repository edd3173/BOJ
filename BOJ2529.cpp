#pragma warning(disable:4996)
#include <utility>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int k;
vector<string> ans;
char numbers[10] = { '0','1','2','3','4','5','6','7','8','9' };
bool check[10] = { false, };
vector<char> str;

bool Okay(string target) {
	for (int i = 0; i < k; i++) {
		if (str[i] == '>') {
			if (target[i] < target[i + 1]) return false;
		}
		else if (str[i] == '<') {
			if (target[i] > target[i + 1]) return false;
		}
	}
	return true;
}

void Go(int idx, string num) {
	if (idx == k + 1) {
		if (Okay(num))
			ans.push_back(num);
		return;
	}
	for (int i = 0; i <= 9; i++) {
		if (check[i]) continue; // already used
		check[i] = true;
		Go(idx + 1, num + numbers[i]);
		check[i] = false;
	}
}

int main() {
	cin >> k;
	str.resize(k);
	for (int i = 0; i < k; i++)
		cin >> str[i];
	Go(0, "");
	string min, max;
	auto p = minmax_element(ans.begin(), ans.end());
	cout << *p.second << endl;
	cout << *p.first << endl;
	return 0;
}
