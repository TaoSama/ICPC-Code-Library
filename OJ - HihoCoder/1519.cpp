#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 500 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
char s[N][N];
int f[N][N][4], in[N][N][4];

int main() {

    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i) scanf("%s", s[i] + 1);
    int sx, sy, tx, ty;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(s[i][j] == 'S') sx = i, sy = j;
            else if(s[i][j] == 'T') tx = i, ty = j;

    memset(f, 0x3f, sizeof f);
    queue<pair<pair<int, int>, int>> q;
    for(int i = 0; i < 4; ++i) {
        f[sx][sy][i] = 0;
        in[sx][sy][i] = 1;
        q.push({{sx, sy}, i});
    }
    while(q.size()) {
        int x, y; tie(x, y) = q.front().first;
        int d = q.front().second; q.pop();
        in[x][y][d] = 0;
        static const int dir[][2] = { -1, 0, 0, -1, 1, 0, 0, 1};
        int nx = x + dir[d][0], ny = y + dir[d][1];
        if(nx < 1 || nx > n || ny < 1 || ny > m || s[nx][ny] == '#') {
            for(int i = 0; i < 4; ++i) {
                if(d == i) continue;
                int nx = x + dir[i][0], ny = y + dir[i][1];
                if(nx < 1 || nx > n || ny < 1 || ny > m || s[nx][ny] == '#')
                    continue;
                if(f[nx][ny][i] > f[x][y][d] + 1) {
                    f[nx][ny][i] = f[x][y][d] + 1;
                    if(!in[nx][ny][i]) in[nx][ny][i] = 1, q.push({{nx, ny}, i});
                }
            }
        } else {
            if(f[nx][ny][d] > f[x][y][d]) {
                f[nx][ny][d] = f[x][y][d];
                if(!in[nx][ny][d]) in[nx][ny][d] = 1, q.push({{nx, ny}, d});
            }
        }
    }
    int ans = INF;
    for(int i = 0; i < 4; ++i) ans = min(ans, f[tx][ty][i]);
    if(ans == INF) ans = -1;
    printf("%d\n", ans);

    return 0;
}
