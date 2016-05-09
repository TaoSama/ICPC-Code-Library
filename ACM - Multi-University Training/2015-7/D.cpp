//
//  Created by TaoSama on 2016-05-09
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
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
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

struct BIT {
    int n, b[N];
    void init(int _n) {
        n = _n;
        memset(b, 0, sizeof b);
    }
    void add(int i, int v) {
        for(; i <= n; i += i & -i) b[i] += v;
    }
    int sum(int i) {
        int ret = 0;
        for(; i; i -= i & -i) ret += b[i];
        return ret;
    }
} bit[2];

int n, op[N], x[N], y[N];
int wh[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    while(scanf("%d", &n) == 1) {
        vector<int> xs[2];
        int addStp = 0;
        for(int i = 1; i <= n; ++i) {
            scanf("%d%d", op + i, x + i);
            if(op[i] == 1) continue;
            wh[++addStp] = i; y[i] = x[i] + addStp;
            xs[0].push_back(x[i]);
            xs[1].push_back(y[i]);
        }
        for(int i = 0; i < 2; ++i) {
            sort(xs[i].begin(), xs[i].end());
            xs[i].resize(unique(xs[i].begin(), xs[i].end()) - xs[i].begin());
            bit[i].init(xs[i].size());
        }

        static int kase = 0;
        printf("Case #%d:\n", ++kase);
        for(int i = 1; i <= n; ++i) {
            if(op[i] == 1) {  //delete
                int t = wh[x[i]];
                int l = lower_bound(xs[0].begin(), xs[0].end(), x[t]) - xs[0].begin() + 1;
                int r = lower_bound(xs[1].begin(), xs[1].end(), y[t]) - xs[1].begin() + 1;

                bit[0].add(l, -1);
                bit[1].add(r, -1);
            } else {
                int l = lower_bound(xs[0].begin(), xs[0].end(), x[i]) - xs[0].begin() + 1;
                int r = lower_bound(xs[1].begin(), xs[1].end(), y[i]) - xs[1].begin() + 1;

                int all = i - 1;
                int out = bit[0].sum(l - 1) + all - bit[1].sum(r);
                printf("%d\n", all - out);

                bit[0].add(l, 1);
                bit[1].add(r, 1);
            }
        }
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
