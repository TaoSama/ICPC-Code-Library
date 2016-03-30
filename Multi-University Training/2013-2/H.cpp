//
//  Created by TaoSama on 2016-02-25
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:1024000000,1024000000")
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
const int N = 3e2 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, a[N][N], b[N][N];
int s[N << 1], p[N][N << 1];

void manacher(int *a, int *p, int n) {
    s[0] = '@'; s[1] = '#';
    int l = 2;
    for(int i = 1; i <= n; ++i) {
        s[l++] = a[i];
        s[l++] = '#';
    }
    s[l] = 0;

    int mx = 0, id;
    for(int i = 1; i < l; ++i) {
        if(mx > i) p[i] = min(mx - i, p[2 * id - i]);
        else p[i] = 1;
        while(s[i - p[i]] == s[i + p[i]]) ++p[i];
        if(mx < p[i] + i) mx = p[i] + i, id = i;
    }
}

struct SparseTable {
    int n, dp[10][N << 1];
    void init(int _n) {
        n = _n;
        for(int i = 1; (1 << i) <= n; ++i)
            for(int j = 1; j + (1 << i) - 1 <= n; ++j)
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j + (1 << i - 1)]);
    }
    int RMQ(int l, int r) {
        int k = 31 - __builtin_clz(r - l + 1);
        return min(dp[k][l], dp[k][r - (1 << k) + 1]);
    }
} hor[N << 1], ver[N << 1];

bool check(int x) {
    int ret = 0;
    for(int i = 1; i <= 2 * n + 1; i += 2) {
        for(int j = 1; j <= 2 * m + 1; j += 2) {
            int right = j + 2 * x, down = i + 2 * x;
            if(right > 2 * m + 1 || down > 2 * n + 1) continue;
            int h = hor[i + x].RMQ(j, right), v = ver[j + x].RMQ(i, down);
            int cur = min(h, v);
            if(cur - 1 >= x) {
                return true;
            }
        }
    }
    return false;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                scanf("%d", &a[i][j]), b[j][i] = a[i][j];

        //rows
        for(int i = 1; i <= n; ++i) manacher(a[i], p[i], m);
        for(int i = 1; i <= 2 * m + 1; ++i) {
            for(int j = 1; j <= 2 * n + 1; ++j) {
                int tmp = INF;
                if(!(j & 1)) tmp = p[j / 2][i];
                ver[i].dp[0][j] = tmp;
            }
            ver[i].init(2 * n + 1);
        }

        //columns
        for(int i = 1; i <= m; ++i) manacher(b[i], p[i], n);
        for(int i = 1; i <= 2 * n + 1; ++i) {
            for(int j = 1; j <= 2 * m + 1; ++j) {
                int tmp = INF;
                if(!(j & 1)) tmp = p[j / 2][i];
                hor[i].dp[0][j] = tmp;
            }
            hor[i].init(2 * m + 1);
        }

        int ans = 0;
        {
            int l = 0, r = 150;
            while(l <= r) {
                int m = l + r >> 1;
                if(check(2 * m)) l = m + 1;
                else r = m - 1;
            }
            --l;
            ans = max(ans, 2 * l);
        }
        {
            int l = 0, r = 150;
            while(l <= r) {
                int m = l + r >> 1;
                if(check(2 * m + 1)) l = m + 1;
                else r = m - 1;
            }
            --l;
            ans = max(ans, 2 * l + 1);
        }
        printf("%d\n", ans);
    }
    return 0;
}
