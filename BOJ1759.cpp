#pragma warning(disable:4996)
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int L, C;
string pwd;

bool Check(string& password) {
	int ja = 0, mo = 0;
	for (char c : password) {
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') mo++;
		else ja++;
	}
	return (ja >= 2 && mo >= 1);
}

void Go(int n, vector<char> &alpha, string password,int idx) {
	// we found the ans
	if (password.length()==n) { // cur pwd length == n.
		if (Check(password)) {
			cout << password << endl;
		}
		return;
	}
	// impossible : i가 alpha의 크기보다 크다. 즉, 더 사용가능한 alphabet이 없다
	if (idx >= alpha.size()) return;

	// case we us i-th alphabet
	Go(n, alpha, password + alpha[idx], idx + 1);
	
	// case we don't use i-th alphabet
	Go(n, alpha, password, idx + 1);
}

int main() {
	cin >> L >> C;
	vector<char> str(C);
	for (int i = 0; i < C; i++) {
		cin >> str[i];
	}

	sort(str.begin(), str.end());
	
	Go(L, str, "", 0);
	
	return 0;
}