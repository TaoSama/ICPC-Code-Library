#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

int n, m, a[505][505];

typedef pair<int, int> P;

int dp[505][505];
int d[][2] = { -1, 0, 0, -1, 1, 0, 0, 1};

int bfs(int sx, int sy) {
    queue<P> q; q.push(P(sx, sy));
    memset(dp, -1, sizeof dp);
    dp[sx][sy] = 0;
    int ret = 0;
    while(q.size()) {
        P u = q.front(); q.pop();
        for(int i = 0; i < 4; ++i) {
            P v = u;
            v.first += d[i][0];
            v.second += d[i][1];
            if(v.first < 1 || v.first > n || v.second < 1 || v.second > m) continue;
            if(dp[v.first][v.second] == -1) {
                dp[v.first][v.second] = dp[u.first][u.second] + 1;
                if(dp[v.first][v.second] & 1) ret += a[v.first][v.second];
                else ret -= a[v.first][v.second];
                q.push(v);
            }
        }
    }
    return ret;
}

int main() {
    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        int sx, sy;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                scanf("%d", &a[i][j]);
                if(a[i][j] == -1) sx = i, sy = j;
            }
        }
        int ans = bfs(sx, sy);
        printf("%d\n", ans);
    }
    return 0;
}
