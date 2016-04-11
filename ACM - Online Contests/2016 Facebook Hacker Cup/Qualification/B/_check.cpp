#include <bits/stdc++.h>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
char a[2][N];
int d[][2] = { -1, 0, 0, -1, 1, 0, 0, 1};

int main() {
//    freopen("in.txt", "r", stdin);
    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 0; i < 2; ++i) scanf("%s", a[i] + 1);

        vector<pair<int, int> > p;
        for(int i = 0; i < 2; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(a[i][j] == '.') p.push_back({i, j});
            }
        }

        int ans = INF;
        for(int s = 1; s < 1 << p.size(); ++s) {
            if(__builtin_popcount(s) >= ans) continue;
            char b[2][N]; memcpy(b, a, sizeof a);
            bool ok = true;
            for(int i = 0; i < p.size(); ++i) {
                if(s >> i & 1) {
                    int x = p[i].first, y = p[i].second;
                    b[x][y] = 'X';
                    for(int k = 0; k < 4; ++k) {
                        int nx = x, ny = y;
                        while(true) {
                            nx += d[k][0], ny += d[k][1];
                            if(nx < 0 || nx >= 2 || ny < 1 || ny > n) break;
                            if(a[nx][ny] == 'X') break;
                            b[nx][ny] = 'X';
                        }
                    }
                }
            }
            if(count(b[0] + 1, b[0] + n + 1, 'X') != n
                    || count(b[1] + 1, b[1] + n + 1, 'X') != n) ok = false;
//         printf("%d: %d\n", __builtin_popcount(s), ok);
            if(ok) ans = min(ans, __builtin_popcount(s));
        }
        static int kase = 0;
        printf("Case #%d: %d\n", ++kase, ans);
    }
    return 0;
}
