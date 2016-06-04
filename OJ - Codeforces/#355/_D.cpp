//
//  Created by TaoSama on 2016-06-02
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
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
#include <bitset>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 300 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, p;
int s[N][N], f[N][N];
typedef pair<int, int> P;
vector<P> G[N * N];

struct BIT {
    int n, b[N][N];
    int timStp, vis[N][N];
    void init(int _n) {
        n = _n;
        timStp = 1;
        memset(vis, 0, sizeof vis);
    }
    void newOne() {
        ++timStp;
    }
    void update(int x, int y, int v) {
        for(int i = x; i <= n; i += i & -i) {
            for(int j = y; j <= n; j += j & -j) {
                if(vis[i][j] != timStp) vis[i][j] = timStp, b[i][j] = INF;
                b[i][j] = min(b[i][j], v);
            }
        }
    }
    int query(int x, int y) {
        int ret = INF;
        for(int i = x; i; i -= i & -i)
            for(int j = y; j; j -= j & -j)
                if(vis[i][j] == timStp) ret = min(ret, b[i][j]);
        return ret;
    }
} bit[4];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    scanf("%d%d%d", &n, &m, &p);
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            scanf("%d", s[i] + j);
            G[s[i][j]].push_back({i, j});
        }
    }

    memset(f, 0x3f, sizeof f);
    int nm = max(n, m);
    for(int i = 0; i < 4; ++i) bit[i].init(nm);
    //UL - f[x2][y2] = min { f[x1][y1] - x1 - y1 + x2 + y2 }
    //UR - f[x2][y2] = min { f[x1][y1] + x1 - y1 - x2 + y2 }
    //BR - f[x2][y2] = min { f[x1][y1] + x1 + y1 - x2 - y2 }
    //BL - f[x2][y2] = min { f[x1][y1] - x1 + y1 + x2 - y2 }
    for(int i = 0; i < G[1].size(); ++i) {
        int x = G[1][i].first, y = G[1][i].second;
        f[x][y] = x + y - 2;
        bit[0].update(x, y, f[x][y] - x - y);
        bit[1].update(nm - x + 1, y, f[x][y] + x - y);
        bit[2].update(nm - x + 1, nm - y + 1, f[x][y] + x + y);
        bit[3].update(x, nm - y + 1, f[x][y] - x + y);
    }

    for(int i = 2; i <= p; ++i) {
        for(int j = 0; j < G[i].size(); ++j) {
            int x = G[i][j].first, y = G[i][j].second, val = INF;
            val = min(val, bit[0].query(x, y) + x + y);
            val = min(val, bit[1].query(nm - x + 1, y) - x + y);
            val = min(val, bit[2].query(nm - x + 1, nm - y + 1) - x - y);
            val = min(val, bit[3].query(x, nm - y + 1) + x - y);
            f[x][y] = val;
        }

        for(int j = 0; j < 4; ++j) bit[j].newOne();
        for(int j = 0; j < G[i].size(); ++j) {
            int x = G[i][j].first, y = G[i][j].second;
            bit[0].update(x, y, f[x][y] - x - y);
            bit[1].update(nm - x + 1, y, f[x][y] + x - y);
            bit[2].update(nm - x + 1, nm - y + 1, f[x][y] + x + y);
            bit[3].update(x, nm - y + 1, f[x][y] - x + y);
        }
    }

    int x = G[p][0].first, y = G[p][0].second;
    printf("%d\n", f[x][y]);

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
