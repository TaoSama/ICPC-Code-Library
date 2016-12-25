//
//  Created by TaoSama on 2016-12-17
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
const int N = 1e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

struct BIT {
    int n, b[N][N];
    void init(int _n) {
        n = _n;
        memset(b, 0, sizeof b);
    }
    void add(int x, int y, int v) {
        for(int i = x; i <= n; i += i & -i)
            for(int j = y; j <= n; j += j & -j)
                b[i][j] += v;
    }
    void add(int x1, int y1, int x2, int y2, int v) {
        add(x2 + 1, y2 + 1, v);
        add(x2 + 1, y1, -v);
        add(x1, y2 + 1, -v);
        add(x1, y1, v);
    }
    int sum(int x, int y) {
        int ret = 0;
        for(int i = x; i; i -= i & -i)
            for(int j = y; j; j -= j & -j)
                ret += b[i][j];
        return ret;
    }
} bit;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        int n, q; scanf("%d%d", &n, &q);
        bit.init(n);
        while(q--) {
            char op[2]; scanf("%s", op);
            if(*op == 'C') {
                int x1, y1, x2, y2; scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
                bit.add(x1, y1, x2, y2, 1);
            } else {
                int x, y; scanf("%d%d", &x, &y);
                printf("%d\n", bit.sum(x, y));
            }
        }
        if(t) puts("");
    }

    return 0;
}
