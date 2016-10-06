//
//  Created by TaoSama on 2016-10-06
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

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 200 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;

int R, C, bR, bC;
int n, g[3 * N][3 * N];
int ox[N], oy[N];
int nox[N], noy[N];

vector<int> xs, ys;
int compress(int* x, vector<int>& xs, int R) {
    xs.clear();
    xs.push_back(1);
    xs.push_back(2);
    xs.push_back(R);
    xs.push_back(R + 1);
    for(int i = 1; i <= n; ++i) {
        for(int d = 0; d <= 1; ++d) {
            int tx = x[i] + d;
            xs.push_back(tx);
        }
    }
    sort(xs.begin(), xs.end());
    xs.resize(unique(xs.begin(), xs.end()) - xs.begin());

    for(int i = 1; i <= n; ++i)
        x[i] = lower_bound(xs.begin(), xs.end(), x[i]) - xs.begin() + 1;
    return xs.size() - 1;
}

inline LL get(int x, int y) {
    return 1LL * abs(xs[x] - xs[x - 1]) * abs(ys[y] - ys[y - 1]);
}

LL bfs(int i, int j, int id) {
    queue<pair<int, int> > q;
    q.push({i, j});
    g[i][j] = id;
    LL ret = 0;
    while(q.size()) {
        int x, y; tie(x, y) = q.front(); q.pop();
        ret += get(x, y);
        static int d[][2] = { -1, 0, 0, -1, 1, 0, 0, 1};
        for(int i = 0; i < 4; ++i) {
            int nx = x + d[i][0], ny = y + d[i][1];
            if(nx < 1 || nx > R || ny < 1 || ny > C) continue;
            if(g[nx][ny]) continue;

//            int dis = get(x, y, nx, ny);
//            printf("%d  (%d, %d) -> (%d, %d) = %d\n", id, x, y, nx, ny, dis);
//            ret += dis;
            g[nx][ny] = id;
            q.push({nx, ny});
        }
    }

    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &R, &C);
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) scanf("%d%d", ox + i, oy + i);

        R = compress(ox, xs, R);
        C = compress(oy, ys, C);

        memset(g, 0, sizeof g);
        for(int i = 1; i <= n; ++i) g[ox[i]][oy[i]] = -1;

        int cnt = 0;
        vector<LL> ans;
        for(int i = 1; i <= R; ++i) {
            for(int j = 1; j <= C; ++j) {
                if(g[i][j]) continue;
                LL ret = bfs(i, j, ++cnt);
                ans.push_back(ret);
            }
        }

        static int kase = 0;
        printf("Case #%d:\n", ++kase);
        printf("%d\n", ans.size());
        sort(ans.begin(), ans.end());
        for(int i = 0; i < ans.size(); ++i) {
            printf("%I64d%c", ans[i], " \n"[i + 1 == ans.size()]);
        }
    }
    return 0;
}
