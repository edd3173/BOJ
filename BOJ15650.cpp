#pragma warning(disable:4996)
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;

int N, M;
bool visited[10] = { false, };
int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };

void go(int idx, int start) {
	if (idx == M) {
		for (int i = 0; i < M; i++)
			printf("%d ", arr[i + 1]);
		return;
	}
	for (int i = start; i <= N; i++) {
		if (visited[i]) continue;
		visited[i] = true; arr[idx] = i;
		go(idx + 1, i + 1);
		visited[i] = false;
	}
}

int main() {
	scanf("%d %d", &N, &M);
	go(0, 1);
}

/*
int a[10];
void Go(int idx, int sel, int n, int m){ // include the number 'idx' or not
if(sel==m){
	Print();
	return;
}
if(idx>n) return;

// idx를 결과에 추가하는 경우
a[sel]=idx;
Go(idx+1, sel+1,n,m);

// idx를 결과에 추가하지 않는 경우
a[sel]=0;
Go(idx+1,sel,n,m);

// Go(1,0,n,m)
*/