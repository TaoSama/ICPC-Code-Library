//
//  Created by TaoSama on 2016-03-01
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
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int C = 2e6 + 10;

int s, w, ans[N];

struct Query {
    int x, y, a;
    int id;
} qs[N], tmp[N];

bool cmpx(const Query& a, const Query& b) {
    return a.x < b.x;
}

//(x2, y2) (x1-1,y1-1) (x1-1, y2) (x2, y1-1)

//maintain y
struct BIT {
    int n, tim, vis[C], b[C];
    void init(int _n) {
        n = _n;
        tim = 0;
        memset(vis, 0, sizeof vis);
    }
    void newOne() {++tim;}
    void add(int i, int v) {
        for(; i <= n; i += i & -i) {
            if(vis[i] != tim) vis[i] = tim, b[i] = 0;
            b[i] += v;
        }
    }
    int sum(int i) {
        int ret = 0;
        for(; i; i -= i & -i)
            if(vis[i] == tim) ret += b[i];
        return ret;
    }
} bit;

void cdq(int l, int r) {
    if(l == r) return;
    int m = l + r >> 1;
    cdq(l, m);

    for(int i = l; i <= r; ++i) tmp[i] = qs[i];
    sort(tmp + l, tmp + m + 1, cmpx);
    sort(tmp + m + 1, tmp + r + 1, cmpx);

    int j = l;
    bit.newOne();
//    pr(l); prln(r);
    for(int i = m + 1; i <= r; ++i) {
        for(; j <= m && tmp[j].x <= tmp[i].x; ++j) {
            if(tmp[j].id < 0) {
//                printf("add (%d, %d): %d\n", tmp[j].x, tmp[j].y, tmp[j].a);
                bit.add(tmp[j].y, tmp[j].a);
            }
        }
        if(tmp[i].id > 0) {
            ans[tmp[i].id] += tmp[i].a * bit.sum(tmp[i].y);
//            printf("query %d: (%d, %d): %d\n",
//                   tmp[i].id, tmp[i].x, tmp[i].y, bit.sum(tmp[i].y));
        }
    }

    cdq(m + 1, r);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &s, &w) == 2) {
        bit.init(w);
        int idx = 0, q = 0;
        int op, x1, y1, x2, y2, a;
        while(scanf("%d", &op) == 1 && op != 3) {
            if(op == 1) {
                scanf("%d%d%d", &x1, &y1, &a);
                qs[++idx] = (Query) {x1, y1, a, -1};
            } else {
                scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
                ans[++q] = s * (x2 - x1 + 1) * (y2 - y1 + 1);
                qs[++idx] = (Query) {x2, y2, +1, q};
                qs[++idx] = (Query) {x1 - 1, y1 - 1, +1, q};
                qs[++idx] = (Query) {x1 - 1, y2, -1, q};
                qs[++idx] = (Query) {x2, y1 - 1, -1, q};
            }
        }
        cdq(1, idx);
        for(int i = 1; i <= q; ++i) printf("%d\n", ans[i]);
    }
    return 0;
}
