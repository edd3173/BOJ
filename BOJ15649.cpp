#pragma warning(disable:4996)
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
bool visited[10] = { false, };
int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };

void Solve(int cnt) {
	// n=4, m=2
	if (cnt == M) { // if we chose #m number, 
		for (int i = 0; i < M; i++)
			cout << arr[i] << " "; // inputted every slot.
		cout << "\n";
		return;
	}
	for (int i = 1; i <= N; i++) { // search through given number
		if (visited[i]) continue; // okay.
		visited[i] = true; // current case : mark
		arr[cnt] = i; // input number in i-th slot
		Solve(cnt + 1); // go to next slot
		visited[i] = 0; // current slot is finished, for next Big iteration, init.
	}
}

// visited[1]=true, arr[0]=1, Solve(1),  : i==1
// Solve(1) : visited[1]=true, so skip current for (i==1, go to i==2), visited[2]=false, so arr[1]=2, Solve(2)
// cnt==2 so PRINT 1,2 then return;
// Then visited[2]=0, visited[1]=0.
// next we start with : i==2
//visited[2]=true, arr[1]=2, Solve(1) : i==2



int main() {
	scanf("%d %d", &N, &M);
	Solve(0);
}