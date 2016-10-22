//
//  Created by TaoSama on 2015-09-14
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
const int N = 1e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int r, n, q;
int Sum, Max, Min;

#define root 1, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

struct SegTree {
    int sum[N << 2], maxv[N << 2], minv[N << 2], setv[N << 2], addv[N << 2];

    void push_up(int rt) {
        sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
        maxv[rt] = max(maxv[rt << 1], maxv[rt << 1 | 1]);
        minv[rt] = min(minv[rt << 1], minv[rt << 1 | 1]);
    }
    void push_down(int rt, int m) {
        if(setv[rt]) {
            setv[rt << 1] = setv[rt << 1 | 1] = setv[rt];
            addv[rt << 1] = addv[rt << 1 | 1] = 0;
            sum[rt << 1] = setv[rt] * (m - (m >> 1));
            sum[rt << 1 | 1] = setv[rt] * (m >> 1);
            maxv[rt << 1] = maxv[rt << 1 | 1] = setv[rt];
            minv[rt << 1] = minv[rt << 1 | 1] = setv[rt];
            setv[rt] = 0;
        }
        if(addv[rt]) {
            addv[rt << 1] += addv[rt];
            addv[rt << 1 | 1] += addv[rt];
            sum[rt << 1] += addv[rt] * (m - (m >> 1));
            sum[rt << 1 | 1] += addv[rt] * (m >> 1);
            maxv[rt << 1] += addv[rt];
            maxv[rt << 1 | 1] += addv[rt];
            minv[rt << 1] += addv[rt];
            minv[rt << 1 | 1] += addv[rt];
            addv[rt] = 0;
        }
    }
    void update(int L, int R, int v, int op, int l, int r, int rt) {
        if(L <= l && r <= R) {
            if(op == 2) {
                setv[rt] = v;
                addv[rt] = 0;
                sum[rt] = (r - l + 1) * v;
                maxv[rt] = minv[rt] = v;
            } else {
                addv[rt] += v;
                sum[rt] += (r - l + 1) * v;
                maxv[rt] += v, minv[rt] += v;
            }
            return;
        }
        int m = l + r >> 1;
        push_down(rt, r - l + 1);
        if(L <= m) update(L, R, v, op, lson);
        if(R > m) update(L, R, v, op, rson);
        push_up(rt);
    }
    void query(int L, int R, int l, int r, int rt) {
        if(L <= l && r <= R) {
            Sum += sum[rt];
            Min = min(Min, minv[rt]);
            Max = max(Max, maxv[rt]);
            return;
        }
        int m = l + r >> 1;
        push_down(rt, r - l + 1);
        if(L <= m) query(L, R, lson);
        if(R > m) query(L, R, rson);
    }
} T[21];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d%d", &r, &n, &q) == 3) {
        memset(T, 0, sizeof T);
        while(q--) {
            int op, x1, x2, y1, y2, v;
            scanf("%d%d%d%d%d", &op, &x1, &y1, &x2, &y2);
            if(op <= 2) {
                scanf("%d", &v);
                for(int i = x1; i <= x2; ++i)
                    T[i].update(y1, y2, v, op, root);
            } else {
                Sum = 0; Max = -INF; Min = INF;
                for(int i = x1; i <= x2; ++i)
                    T[i].query(y1, y2, root);
                printf("%d %d %d\n", Sum, Min, Max);
            }
        }
    }
    return 0;
}
