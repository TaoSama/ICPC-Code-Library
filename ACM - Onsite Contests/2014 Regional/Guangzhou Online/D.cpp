//
//  Created by TaoSama on 2015-10-23
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

int n, k;
char a[105][105];
int dp[105][105][10][1 << 5];
int sx, sy;

typedef pair<int, int> P;

struct Sta {
    int x, y, s, t;
    Sta(int x = 0, int y = 0, int s = 0, int t = 0): x(x), y(y), s(s), t(t) {}
};

int d[][2] = { -1, 0, 0, -1, 1, 0, 0, 1};

int bfs() {
    queue<Sta> q;
    q.push(Sta(sx, sy, 0, 0));
    memset(dp, 0x3f, sizeof dp);
    dp[sx][sy][0][0] = 0;
    while(q.size()) {
        Sta u = q.front(), v = u; q.pop();
        if(a[u.x][u.y] == 'T' && u.s == k)
            return dp[u.x][u.y][u.s][u.t];
        if(islower(a[v.x][v.y])) {
            int num = a[v.x][v.y] - 'a';
            if(!(v.t >> num & 1)) {
                dp[v.x][v.y][v.s][v.t | (1 << num)] = dp[v.x][v.y][v.s][v.t] + 1;
                v.t |= 1 << num;
                q.push(v);
                continue;
            }
        }
        for(int i = 0; i < 4; ++i) {
            v = u;
            v.x += d[i][0], v.y += d[i][1];
            if(v.x < 1 || v.x > n || v.y < 1 || v.y > n || a[v.x][v.y] == '#') continue;
            if(isdigit(a[v.x][v.y])) {
                int num = a[v.x][v.y] - '0';
                if(v.s == num - 1) v.s = num;
            }
            if(dp[v.x][v.y][v.s][v.t] == INF) {
                dp[v.x][v.y][v.s][v.t] = dp[u.x][u.y][u.s][u.t] + 1;
                q.push(v);
            }
        }
    }
    return INF;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &k) == 2 && (n || k)) {
        int id = 'a';
        for(int i = 1; i <= n; ++i) {
            scanf("%s", a[i] + 1);
            for(int j = 1; j <= n; ++j)
                if(a[i][j] == 'K') sx = i, sy = j;
                else if(a[i][j] == 'S') a[i][j] = id++;
        }
        int ans = bfs();
        if(ans != INF) printf("%d\n", ans);
        else puts("impossible");
    }
    return 0;
}
