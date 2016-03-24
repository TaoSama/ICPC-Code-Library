//
//  Created by TaoSama on 2015-08-13
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

int n, v, s;
struct P {
    int x, c, delta;
    bool operator< (const P& rhs) const {
        return x < rhs.x;
    }
} a[1005];

double sum[1005], dp[1005][1005][2];
int kase, vis[1005][1005][2];

double cost(P& a, P& b, int l, int r) {
    double t = 1.0 * abs(a.x - b.x) / v;
    return 1.0 * b.c + (sum[l - 1] + sum[n] - sum[r]) * t;
}

double dfs(int l, int r, bool f) {
    double &ret = dp[l][r][f];
    if(vis[l][r][f] == kase) return ret;
    if(l == 1 && r == n) return 0;
    vis[l][r][f] = kase;

    ret = INF;
    P &cur = f ? a[r] : a[l];
    if(r < n) ret = min(ret, dfs(l, r + 1, 1) + cost(cur, a[r + 1], l, r));
    if(l > 1) ret = min(ret, dfs(l - 1, r, 0) + cost(cur, a[l - 1], l, r));
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    kase = 0;
    while(scanf("%d%d%d", &n, &v, &s) == 3 && (n || v || s)) {
        for(int i = 1; i <= n; ++i) scanf("%d%d%d", &a[i].x, &a[i].c, &a[i].delta);
        a[++n].x = s; a[n].c = a[n].delta = 0;
        sort(a + 1, a + n + 1);
        for(int i = 1; i <= n; ++i) {
            if(a[i].x == s) s = i;
            sum[i] = sum[i - 1] + a[i].delta;
        }

        ++kase;
        int ans = min(dfs(s, s, 0), dfs(s, s, 1));
        printf("%d\n", ans);
    }
    return 0;
}
