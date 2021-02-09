#pragma warning(disable:4996)
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>

int n, m;
int arr[500][500];
int ans;

int b[19][4][2] = {
    { {0,0}, {0,1}, {1,0}, {1,1} }, // ㅁ
    { {0,0}, {0,1}, {0,2}, {0,3} }, // ㅡ
    { {0,0}, {1,0}, {2,0}, {3,0} },
    { {0,0}, {0,1}, {0,2}, {1,0} }, // ㄴ
    { {0,2}, {1,0}, {1,1}, {1,2} },
    { {0,0}, {1,0}, {1,1}, {1,2} },
    { {0,0}, {0,1}, {0,2}, {1,2} },
    { {0,0}, {1,0}, {2,0}, {2,1} },
    { {0,0}, {0,1}, {1,1}, {2,1} },
    { {0,0}, {0,1}, {1,0}, {2,0} },
    { {0,1}, {1,1}, {2,0}, {2,1} },
    { {0,0}, {1,0}, {1,1}, {2,1} }, // Z
    { {0,1}, {1,0}, {1,1}, {2,0} },
    { {0,1}, {0,2}, {1,0}, {1,1} },
    { {0,0}, {0,1}, {1,1}, {1,2} },
    { {0,0}, {0,1}, {0,2}, {1,1} }, // ㅗ
    { {0,1}, {1,0}, {1,1}, {1,2} },
    { {0,1}, {1,0}, {1,1}, {2,1} },
    { {0,0}, {1,0}, {1,1}, {2,0} }
};


/*


*/
void Tet(int x, int y) {
    for (int i = 0; i < 19; i++) {
        int res = 0; // init.
        for (int j = 0; j < 4; j++) {
            int nx = x + b[i][j][0]; // 초기 꼭지점의 x. x가 더해지는 이유는 보드의 상대적 위치
            int ny = y + b[i][j][1];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                res += arr[nx][ny];
            }
        }
        if (ans < res) ans = res;
    }
}

void Solve() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            Tet(i, j);
        }
    }
    printf("%d\n", ans);
}

int main() {
	int i, j;
	scanf("%d %d", &n, &m);

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
    Solve();

    return 0;
}

