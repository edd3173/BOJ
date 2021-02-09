#pragma warning(disable:4996)
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int ans = INT_MAX;
bool c[20];
int S[20][20];

void Solve(int cnt, int idx) {
    if (idx == N) return; // we looked all idx

    if (cnt == N / 2) { // we choose N/2 member as team1
        int s1 = 0, s2 = 0; // sum of each team
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == j) continue;
                if (c[i] && c[j]) s1 += S[i][j]; // 1st team
                if (!c[i] && !c[j]) s2 += S[i][j]; // 2nd team
            }
        }
        ans = min(ans, abs(s1 - s2)); // update
        return;
    }

    // case idx is team 1
    c[idx] = true;
    Solve(cnt + 1, idx + 1);

    // case idx is team 2
    c[idx] = false;
    Solve(cnt, idx + 1);
}

int main() {
	cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &S[i][j]);
        }
    }
    Solve(0, 0);
    printf("%d\n", ans);
    return 0;
}