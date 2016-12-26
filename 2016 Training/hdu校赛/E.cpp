#include <bits/stdc++.h>
using namespace std;
#define pr(x)   cout << #x << " = " << x << " "
#define prln(x) cout << #x << " = " << x << endl
const int N = 50 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
bool vis[N][N];
int d[][2] = { -1, 0, 0, -1, 1, 0, 0, 1};

struct Maze {
    char a[N][N];
    void see() {
        for(int i = 1; i <= n; ++i) puts(a[i] + 1);
        puts("");
    }
} s;

bool check(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

bool newOne(Maze& maze, int dir) {
    auto a = maze.a;
    int ok = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(a[i][j] != 'o') continue;
            int x = i + d[dir][0], y = j + d[dir][1];
            if(!check(x, y) || a[x][y] == '#') return false;
            if(!vis[x][y]) ++ok;
        }
    }
    return ok;
}

void goOne(Maze& maze, int dir) {
    auto a = maze.a;
    if(dir == 0) {
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                if(a[i][j] != 'o') continue;
                int x = i + d[dir][0], y = j + d[dir][1];
                a[x][y] = 'o';
                vis[x][y] = true;
                a[i][j] = '.';
            }
        }
    } else if(dir == 1) {
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                if(a[i][j] != 'o') continue;
                int x = i + d[dir][0], y = j + d[dir][1];
                a[x][y] = 'o';
                vis[x][y] = true;
                a[i][j] = '.';
            }
        }
    } else if(dir == 2) {
        for(int i = n; i; --i) {
            for(int j = m; j; --j) {
                if(a[i][j] != 'o') continue;
                int x = i + d[dir][0], y = j + d[dir][1];
                a[x][y] = 'o';
                vis[x][y] = true;
                a[i][j] = '.';
            }
        }
    } else {
        for(int i = n; i; --i) {
            for(int j = m; j; --j) {
                if(a[i][j] != 'o') continue;
                int x = i + d[dir][0], y = j + d[dir][1];
                a[x][y] = 'o';
                vis[x][y] = true;
                a[i][j] = '.';
            }
        }
    }

}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\luwt\\Desktop\\in.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(false);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        memset(vis, 0, sizeof vis);
        memset(s.a, 0, sizeof s.a);
        for(int i = 1; i <= n; ++i) {
            scanf("%s", s.a[i] + 1);
            for(int j = 1; j <= m; ++j) {
                if(s.a[i][j] == 'o') vis[i][j] = 1;
            }
        }

        queue<Maze> q; q.push(s);
        while(q.size()) {
            Maze u = q.front(); q.pop();
            for(int i = 0; i < 4; ++i) {
                if(newOne(u, i)) {
                    Maze v = u;
                    goOne(v, i);
                    q.push(v);
                }
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                ans += vis[i][j];
        static int kase = 0;
        printf("Case #%d: %d\n", ++kase, ans);
    }
    return 0;
}
