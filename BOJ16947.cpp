#pragma warning(disable:4996)
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
// 馬蟹亀 乞牽畏革 せせせせせせせせせせせ
int n;

int check[3001] = { -1, };
vector<int> arr[3001];
int dist[3001];

int Go(int x, int p) { // p拭辞 x稽 尽製. y稽 哀 暗績.
	if (check[x] == 1) return x; // 紫戚適聖 達製
	check[x] = 1; // 号庚
	for (int y : arr[x]) {
		if (y == p) continue; // 戚穿 舛繊引 旭生檎 什典
		int res = Go(y, x); // 飴重.
		if (res == -2) return -2; // cycle聖 達紹澗汽 匂敗鞠走 たしう製
		if (res >= 0) { // cycle達製. 匂敗鞠走 省精 井酔研 杏袈生艦 戚暗澗 達精暗績.
			check[x] = 2; // 号庚梅澗汽 紫戚適税 析採績
			if (x == res) return -2; // 嬢, 紫戚適戚 獣拙吉 走繊戚革? 益軍 蒋生稽税 軒渡葵精 -2亜 鞠嬢醤
			else return res;
		}
	}
	return -1;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u -= 1; v -= 1;
		arr[u].push_back(v);
		arr[v].push_back(u);
	}
	Go(0, -1);

	queue<int> q;
	for (int i = 0; i < n; i++) {
		if (check[i] == 2) {
			dist[i] = 0; // 授発繊戚陥
			q.push(i);
		}
		else {
			dist[i] = -1; // -1戚虞 敗精, 焼送 号庚馬走 省精 依.
		}
	}

	//BFS 
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int y : arr[x]) {
			if (dist[y] == -1) {
				q.push(y);
				dist[y] = dist[x] + 1;
			}
		}
	}

	for (int i = 0; i < n; i++)
		cout << dist[i] << ' ';
	cout << endl;
	return 0;

}