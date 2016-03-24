//
//  Created by TaoSama on 2015-07-30
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
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
const int N = 35, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, maxd, cnt;
int ans[N], cur[N], vis[N][N]; // to reuse the vis
int a[N][N];

struct P {
    int x, y, v;
    P() {}
    P(int x, int y, int v): x(x), y(y), v(v) {}
    bool operator< (const P& rhs) const {
        return v > rhs.v;
    }
};

int d[][2] = { -1, 0, 0, -1, 1, 0, 0, 1};

//check how many digits are can by arrived by (x,y)
int h(int x, int y) {
    int ret = 0;
    vis[x][y] = cnt;
    for(int i = 0; i < 4; ++i) {
        int nx = x + d[i][0], ny = y + d[i][1];
        if(!a[nx][ny] || vis[nx][ny] == cnt) continue;
        ret += h(nx, ny) + 1;
    }
    return ret;
}

bool isLess(int dep) {
    for(int i = 0; i < dep; ++i)
        if(ans[i] != cur[i]) return ans[i] < cur[i];
    return false;
}

bool dfs(int x, int y, bool same, int dep) {
    if(same) {
        for(int i = 0; i < dep; ++i)
            if(cur[i] < ans[i]) return false;
    }
    if(ans[dep] > cur[dep]) same = false;
    if(dep == maxd) {
        if(isLess(dep)) {
            for(int i = 0; i < maxd; ++i) ans[i] = cur[i];
        }
        return true;
    }
    ++cnt;
    if(dep + h(x, y) < maxd) return false;

    vector<P> L;
    for(int i = 0; i < 4; ++i) {
        int nx = x + d[i][0], ny = y + d[i][1];
        if(a[nx][ny]) L.push_back(P(nx, ny, a[nx][ny]));
    }
    sort(L.begin(), L.end());

    bool o = false;
    for(auto &p : L) {
        int &t = a[p.x][p.y];
        int tmp = t;  t = 0;
        cur[dep] = p.v;
        o |= dfs(p.x, p.y, same, dep + 1);
        t = tmp;
    }
    return o;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
//    ios_base::sync_with_stdio(0);

//    time_t st = clock();

    while(scanf("%d%d", &n, &m)  == 2 && (n || m)) {
        memset(a, 0, sizeof a);
        memset(vis, 0, sizeof vis);
        memset(ans, 0, sizeof ans);
        maxd = cnt = 0;

        vector<P> L;
        for(int i = 1; i <= n; ++i) {
            char buf[N]; scanf("%s", buf + 1);
            for(int j = 1; j <= m; ++j) {
                if(buf[j] != '#') {
                    a[i][j] = buf[j] - '0';
                    L.push_back(P(i, j, a[i][j]));
                    maxd++;
                }
            }
        }
        sort(L.begin(), L.end());

        for(; maxd; --maxd) {
            bool o = false;
            for(auto &p : L) {
                int &now = a[p.x][p.y];
                int tmp = now;  now = 0;
                cur[0] = p.v;
                o |= dfs(p.x, p.y, o, 1);
                now = tmp;
            }
            if(o) break;
        }

        for(int i = 0; i < maxd; ++i) printf("%d", ans[i]);
        puts("");
    }


//    time_t ed = clock();
//    cout << (double)(ed - st) / CLOCKS_PER_SEC * 1000 << "ms";
    return 0;
}
