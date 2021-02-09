#pragma warning(disable:4996)
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int n;

typedef struct _node {
	int left;
	int right;

	// 현재 노드의 방문순서. 그리고 깊이를 알기 위해서.
	int order;
	int depth;
}Node;

Node arr[10001];
int Left[10001];
int Right[10001];
int parent[10001]; // root를 찾기 위해. parent[2]는 2번 노드의 parent의 갯수를 의미한다.
// 따라서, parent[k]==0이라면 k번째 node는 root가 된다.

int order = 1;

void inorder(int node, int depth) {
	if (node == -1) return;
	inorder(arr[node].left, depth + 1);
	// 가장 먼저 방문함에 따라 방문순서 order가 카운트 된다. 1번째는 1
	// 현재 depth를 node의 depth에 저장.
	arr[node].order = order++;
	arr[node].depth = depth;

	inorder(arr[node].right, depth + 1);
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		arr[x].left = y; arr[x].right = z;
		parent[y]++; parent[z]++;
	}

	int root = 0;
	int depth = 1;
	
	for (int i = 1; i <= n; i++) {
		if (parent[i] == 0) root = i;
	}
	inorder(root, depth);
	
	int maxDepth = 0;

	for (int i = 1; i <= n; i++) {
		int curDepth = arr[i].depth;
		int curOrder = arr[i].order;

		// Left[curDepth] : curDepth의 depth에서 order의 최소값(min)을 말함.
		// 즉, 가장 작은 노드의 순번. 즉, 가장 왼쪽에 있는 노드.
		if (Left[curDepth] == 0) Left[curDepth] = order;
		else Left[curDepth] = min(Left[curDepth], order);

		// 따라서 right의 경우에는 max를 해준다
		// 덤으로 최고 레벨도 찾음.
		Right[curDepth] = max(Right[curDepth], order);
		maxDepth = max(maxDepth, curDepth);
	}

	int ans = 0;
	int ansLevel = 0;
	// 최고 레벨을 돌며 너비를 찾는다.
	for (int i = 1; i <= maxDepth; i++) {
		if (ans < Right[i] - Left[i] + 1) {
			ans = Right[i] - Left[i] + 1;
			ansLevel = i;
		}
	}
	
	cout << ansLevel << ' ' << ans << endl;

	return 0;
}