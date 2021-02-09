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
int n;

int arr[30][30];
int group[30][30];
int cnt = 0;
int ans[26 * 26];

// for X and Y movement
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void BFS(int i, int j, int cnt) {
	// visited나 arr조건은 이미 걸러지니까 그냥 실행하면됨.
	queue<pair<int, int>> q;
	q.push(make_pair(i, j)); group[i][j] = cnt;
	// group에 cnt 넣기 ㅇㅇ. 종류를 나타내게됨.

	while (!q.empty()) {
		// ㅇㅇ.
		i = q.front().first; j = q.front().second; q.pop();
		// x,y의 movement인데, 좌우상하로만 움직이면 결국 다 커버할 수 있음.
		for (int k = 0; k < 4; k++) {
			// 따라서 이렇게 한다.
			int nx = i + dx[k];
			int ny = j + dy[k]; 

			// 바운더리 체크
			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				// 유효하고, unvisited라며느 
				if (arr[nx][ny] == 1 && group[nx][ny] == 0) {
					q.push(make_pair(nx, ny));
					group[nx][ny] = cnt;
				}
			}
		}
	}
}

void DFS(int x, int y, int cnt) {
	group[x][y] = cnt;
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (0 <= nx && nx < n && 0 <= ny && ny < n) {
			if (arr[nx][ny] == 1 && group[nx][ny] == 0)
				DFS(nx, ny, cnt);
		}
	}
}


int main() {

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			scanf("%1d", &arr[i][j]); // 중요! 우리는 input이 int임을 알지만
		// computer는 10111이 5개의 숫자인지, 1개의 숫자인지 모른다!
		// 따라서 %1d를 해주는거임 ㅇㅇ
	}

	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 26; j++)
			group[i][j] = 0;
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			// 조건 따지기. 유의미한 배열, 그리고 not visited.
			if (arr[i][j] == 1 && group[i][j] == 0)
				BFS(i, j, ++cnt); // group이 1이상이라는건 visited를 의미.
				//DFS(i, j, ++cnt);
		}
	}

	cout << cnt << endl;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			ans[group[i][j]]++;
	}

	sort(ans + 1, ans + cnt + 1); // 시작은 1부터니까 ans+1, 
	// 끝나는 건 cnt, ans의 원소 개수는 group의 종류와 같음.
	for (int i = 1; i <= cnt; i++) {
		cout << ans[i] << endl;
	}


	return 0;
}