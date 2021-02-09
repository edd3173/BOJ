#pragma warning(disable:4996)
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int k;
int s[12] = { 0, };

void Solve() {
	// permutation of 0and1. 0010100.
	// 0 mean choose, so we choose s[idx]
	vector<int> d;
	for (int i = 0; i < k-6; i++)
		d.push_back(0); // not chosen
	for (int i = 0; i < 6; i++)
		d.push_back(1); // chosen

	
	vector<vector<int>> ans; // ans set of picking 6
	do {
		vector<int> cur; // current int vector, element of ans
		for (int i = 0; i < k; i++) 
			if (d[i] == 1) cur.push_back(s[i]); // if d's ele is 1, (chosen), push s[i]
		ans.push_back(cur); // add to set ans
	} while (next_permutation(d.begin(), d.end())); // keep generating d, with permutation
	
	sort(ans.begin(), ans.end()); // sort the ans.
	for (auto& v : ans) {
		for (int i = 0; i < v.size(); i++)
			cout << v[i] << ' '; // print it.
		cout << '\n';
	}
	cout << '\n';
}

int main() {
	while (true) {
		cin >> k;
		if (k == 0) exit(0);
		for (int i = 0; i < k; i++)
			cin >> s[i];
		Solve();
	}
}