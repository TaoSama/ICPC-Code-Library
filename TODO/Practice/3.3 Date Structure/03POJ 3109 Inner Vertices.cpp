//
//  Created by TaoSama on 2015-07-16
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

int n, xMax, yMax, x[N], y[N];
bool vis[N];
vector<int> h[N];

#define root 1, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

int sum[N << 2], add[N << 2];

void push_up(int rt) {
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}
void push_down(int rt, int m) {
    if(add[rt]) {
        sum[rt << 1] += add[rt] * (m - (m >> 1));
        sum[rt << 1 | 1] += add[rt] * (m >> 1);
        add[rt << 1] += add[rt];
        add[rt << 1 | 1] += add[rt];
        add[rt] = 0;
    }
}
void update(int L, int R, int v, int l, int r, int rt) {
    if(L <= l && r <= R) {
        add[rt] += v;
        sum[rt] += v * (r - l + 1);
        return;
    }
    push_down(rt, r - l + 1);
    int m = l + r >> 1;
    if(L <= m) update(L, R, v, lson);
    if(R > m) update(L, R, v, rson);
    push_up(rt);
}
int query(int o, int l, int r, int rt) {
    if(l == r) return sum[rt];
    push_down(rt, r - l + 1);
    int m = l + r >> 1;
    if(o <= m) return query(o, lson);
    else return query(o, rson);
}

int compress(int *p) {
    vector<int> xs(n);
    for(int i = 1; i <= n; ++i) xs[i - 1] = p[i];
    sort(xs.begin(), xs.end());
    xs.resize(unique(xs.begin(), xs.end()) - xs.begin());
    for(int i = 1; i <= n; ++i)
        p[i] = lower_bound(xs.begin(), xs.end(), p[i]) - xs.begin() + 1;
    return xs.size();
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        memset(vis, false, sizeof vis);
        for(int i = 1; i <= n; ++i) {
            h[i].clear();
            scanf("%d%d", x + i, y + i);
        }
        xMax = compress(x);
        yMax = compress(y);

        for(int i = 1; i <= n; ++i) h[y[i]].push_back(x[i]);

        long long ans = n;
        memset(sum, 0, sizeof sum);
        memset(add, 0, sizeof add);
        for(int i = 1; i <= yMax; ++i) {
            sort(h[i].begin(), h[i].end());
            for(int j = 0; j < h[i].size(); ++j) {
                int x = h[i][j];
                int s = query(x, root);
//                pr(x); prln(s);
                if(vis[x]) ans += s;
                else vis[x] = true;
                update(x, x, -s, root);
                if(j + 1 < h[i].size() && x + 1 <= h[i][j + 1] - 1)
                    update(x + 1, h[i][j + 1] - 1, 1, root);
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
