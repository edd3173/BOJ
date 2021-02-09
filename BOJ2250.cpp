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

	// ���� ����� �湮����. �׸��� ���̸� �˱� ���ؼ�.
	int order;
	int depth;
}Node;

Node arr[10001];
int Left[10001];
int Right[10001];
int parent[10001]; // root�� ã�� ����. parent[2]�� 2�� ����� parent�� ������ �ǹ��Ѵ�.
// ����, parent[k]==0�̶�� k��° node�� root�� �ȴ�.

int order = 1;

void inorder(int node, int depth) {
	if (node == -1) return;
	inorder(arr[node].left, depth + 1);
	// ���� ���� �湮�Կ� ���� �湮���� order�� ī��Ʈ �ȴ�. 1��°�� 1
	// ���� depth�� node�� depth�� ����.
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

		// Left[curDepth] : curDepth�� depth���� order�� �ּҰ�(min)�� ����.
		// ��, ���� ���� ����� ����. ��, ���� ���ʿ� �ִ� ���.
		if (Left[curDepth] == 0) Left[curDepth] = order;
		else Left[curDepth] = min(Left[curDepth], order);

		// ���� right�� ��쿡�� max�� ���ش�
		// ������ �ְ� ������ ã��.
		Right[curDepth] = max(Right[curDepth], order);
		maxDepth = max(maxDepth, curDepth);
	}

	int ans = 0;
	int ansLevel = 0;
	// �ְ� ������ ���� �ʺ� ã�´�.
	for (int i = 1; i <= maxDepth; i++) {
		if (ans < Right[i] - Left[i] + 1) {
			ans = Right[i] - Left[i] + 1;
			ansLevel = i;
		}
	}
	
	cout << ansLevel << ' ' << ans << endl;

	return 0;
}