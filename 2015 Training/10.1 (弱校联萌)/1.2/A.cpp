//
//  Created by TaoSama on 2015-10-02
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <vector>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, S;
int dp[1 << 10][2][55][55];
char a[55][55];
bool key[10][55][55];

struct Sta {
    int s, f, x, y;
    Sta() {}
    Sta(int x, int y): s(0), f(0), x(x), y(y) {}
};

void printSta(Sta& u) {
    printf("s: %d f: %d x: %d y: %d", u.s, u.f, u.x, u.y);
}

int d[][2] = { -1, 0, 0, -1, 1, 0, 0, 1};

bool check(Sta& u) {
    if(a[u.x][u.y] == '|') return true;
    if(a[u.x][u.y] == '#') return false;
    bool f = a[u.x][u.y] == '^' || isupper(a[u.x][u.y]);
//    printf("? %d\n", f);
    for(int i = 0; i < S; ++i)
        if(u.s >> i & 1) f ^= key[i][u.x][u.y];
    return u.f == f;
}

int bfs(int sx, int sy) {
    queue<Sta> q;
    memset(dp, -1, sizeof dp);
    Sta s = Sta(sx, sy); q.push(s);
    dp[0][0][sx][sy] = 0;
    while(q.size()) {
        Sta u = q.front(), v; q.pop();
        if(a[u.x][u.y] == '&') return dp[u.s][u.f][u.x][u.y];
        if(a[u.x][u.y] == '|') { //stair
            v = u;
            v.f ^= 1;
            if(dp[v.s][v.f][v.x][v.y] == -1) {
                dp[v.s][v.f][v.x][v.y] = dp[u.s][u.f][u.x][u.y] + 1;
                q.push(v);
            }
        }
        if(isalpha(a[u.x][u.y])) { //switch
            int k = tolower(a[u.x][u.y]) - 'a';
            v = u;
            v.f ^= key[k][u.x][u.y];
            v.s ^= 1 << k;
            if(dp[v.s][v.f][v.x][v.y] == -1) {
                dp[v.s][v.f][v.x][v.y] = dp[u.s][u.f][u.x][u.y] + 1;
                q.push(v);
            }
        }
        for(int i = 0; i < 4; ++i) {
            v = u;
            v.x += d[i][0];
            v.y += d[i][1];
            if(check(v)) {
                if(dp[v.s][v.f][v.x][v.y] == -1) {
                    dp[v.s][v.f][v.x][v.y] = dp[u.s][u.f][u.x][u.y] + 1;
                    q.push(v);
                }
            }
        }
    }
    return -1;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &m, &n) == 2) {
        int sx, sy;
        for(int i = 1; i <= n; ++i) {
            scanf("%s", a[i] + 1);
            for(int j = 1; j <= m; ++j)
                if(a[i][j] == '%') sx = i, sy = j;
        }
        scanf("%d", &S);
        memset(key, false, sizeof key);
        for(int k = 0; k < S; ++k) {
            for(int i = 1; i <= n; ++i) {
                char buf[55]; scanf("%s", buf + 1);
                for(int j = 1; j <= m; ++j)
                    if(buf[j] == '*')
                        key[k][i][j] = 1;
            }
        }
        printf("%d\n", bfs(sx, sy));
    }
    return 0;
}
