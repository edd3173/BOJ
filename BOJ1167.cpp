#pragma warning(disable:4996)
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

// 구조체
struct Edge {
    int to;
    int cost;
    //생성자
    Edge(int to, int cost) : to(to), cost(cost) {
    }
};

vector<Edge> a[100001];
bool check[100001];
int dist[100001];

// start부터 bfs 시작.
void bfs(int start) {
    // 초기화.
    memset(dist, 0, sizeof(dist));
    memset(check, false, sizeof(check));
    
    // BFS시작.
    queue<int> q;
    check[start] = true;
    q.push(start);

    while (!q.empty()) {
        // vertex number
        int x = q.front();
        q.pop();
        for (int i = 0; i < a[x].size(); i++) {
            Edge& e = a[x][i]; // x에서 다음으로 방문할 edge
            if (check[e.to] == false) { // 방문안했다면
                dist[e.to] = dist[x] + e.cost; // 갱신
                q.push(e.to); // 다음 목적지
                check[e.to] = true;
            }
        }
    }
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        while (true) {
            int y, z;
            scanf("%d", &y);
            if (y == -1) break;
            scanf("%d", &z);
            // edge를 생성하고 넣는다.
            a[x].push_back(Edge(y, z));
        }
    }
    // 함 돌려봐라
    bfs(1);
    int start = 1;
    for (int i = 2; i <= n; i++) {
        if (dist[i] > dist[start]) {
            start = i;
        }
    }
    // 거리가 가장 먼 정점을 start라고 한다.
    // 리프 노드를 찾는거같음

    // 그리고 start부터 시작함
    bfs(start);
    int ans = dist[1];
    // 가장 먼 것을 구한다.
    for (int i = 2; i <= n; i++) {
        if (ans < dist[i]) {
            ans = dist[i];
        }
    }
    printf("%d\n", ans);
    return 0;
}
// 어렵네

/*
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
struct Edge {
    int to;
    int cost;
    Edge(int to, int cost) : to(to), cost(cost) {
    }
};
vector<Edge> a[100001];
bool check[100001];
pair<int, int> dfs(int x) { // first: diameter, second: height
    check[x] = true;
    vector<int> heights;
    int ans = 0;
    for (auto &e : a[x]) {
        int y = e.to;
        int cost = e.cost;
        if (check[y] == false) {
            auto p = dfs(y);
            if (ans < p.first) ans = p.first;
            heights.push_back(p.second+cost);
        }
    }
    int height = 0;
    sort(heights.begin(), heights.end());
    reverse(heights.begin(), heights.end());
    if (heights.size() >= 1) {
        height = heights[0];
        if (ans < height) {
            ans = height;
        }
    }
    if (heights.size() >= 2) {
        if (ans < heights[0] + heights[1]) {
            ans = heights[0] + heights[1];
        }
    }
    return make_pair(ans, height);
}
int main() {
    int n;
    scanf("%d",&n);
    for (int i=1; i<=n; i++) {
        int x;
        scanf("%d",&x);
        while (true) {
            int y, z;
            scanf("%d",&y);
            if (y == -1) break;
            scanf("%d",&z);
            a[x].push_back(Edge(y,z));
        }
    }
    auto ans = dfs(1);
    cout << ans.first << '\n';
    return 0;
}*/