#include <iostream>
#include <vector>

using namespace std;

int dx[] = { -1, 0, 0, 1 };
int dy[] = { 0, -1, 1, 0 };
/*

(0,0)을 중심으로 4방향 탐색할 수 있다는 뜻!

OXO
XOX
OXO

OXOO
XOXO
OXOO
OOOO

*/

int N, M;
int result = 0;
vector<vector<int> > arr;
vector<vector<bool> > visited;

int max(int a, int b) {
    return a > b ? a : b;
}

void search(int x, int y, int cnt, int sum) {
    if (cnt >= 4) {
        result = max(result, sum);
        return;
    }
    for (int i = 0; i < 4; i++) {
        // go up,down,right,left
        int nx = x + dx[i];
        int ny = y + dy[i];

        // if cur pos not availabel, continue
        if (nx<1 || ny<1 || nx>N || ny>M || visited[nx][ny]) continue;
        
        // we visited
        visited[nx][ny] = true;

        // search 
        search(nx, ny, cnt + 1, sum + arr[nx][ny]);

        // for next direction search, we need to init visited. 
        visited[nx][ny] = false;
    }
}

void searchFxxk(int x, int y) {
    int sum = arr[x][y]; // init. central part is already added,
    int cnt = 1;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx<1 || ny<1 || nx>N || ny>M || visited[nx][ny]) continue;
        sum += arr[nx][ny]; // so this makes + shape.
        cnt++;
    }
    if (cnt == 4) {
        result = max(result, sum);
        return;
    }
    if (cnt < 4) return;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx<1 || ny<1 || nx>N || ny>M || visited[nx][ny]) continue;
        result = max(result, sum - arr[nx][ny]);
    }

}

int main() {
    cin >> N >> M;
    arr = vector<vector<int> >(N + 1, vector<int>(M + 1));
    visited = vector<vector<bool> >(N + 1, vector<bool>(M + 1, false));

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            cin >> arr[i][j];

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            // 백트래킹 탐색
            visited[i][j] = true;
            search(i, j, 1, arr[i][j]); // arr[i][j] is initial value, added in start coord.

            // for ㅗ search, init.
            visited[i][j] = false;
            // ㅗ모양 탐색
            searchFxxk(i, j);
        }
    }

    cout << result;

    return 0;
}