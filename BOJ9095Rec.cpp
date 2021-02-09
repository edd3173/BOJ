#pragma warning(disable:4996)
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int Go(int cnt, int sum, int goal) {
	if (sum > goal)	return 0;
	if (sum == goal)	return 1; // yes
	int now = 0;
	for (int i = 1; i <= 3; i++){
		now += Go(cnt + 1, sum + i, goal);
		// when 1,2,3 is added.
	}
	return now;
}