//
//  Created by TaoSama on 2015-06-28
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
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

#define root 1, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

struct SegTree {
    int Max[N * 6], lazy[N * 6];

    void push_up(int rt) {
        Max[rt] = max(Max[rt << 1], Max[rt << 1 | 1]);
    }

    void push_down(int rt) {
        if(~lazy[rt]) {
            Max[rt << 1] = max(Max[rt << 1], lazy[rt]);
            Max[rt << 1 | 1] = max(Max[rt << 1 | 1], lazy[rt]);
            lazy[rt << 1] = max(lazy[rt << 1], lazy[rt]);
            lazy[rt << 1 | 1] = max(lazy[rt << 1 | 1], lazy[rt]);
            lazy[rt] = -1;
        }
    }

    void build(int l, int r, int rt) {
        Max[rt] = 0; lazy[rt] = -1;
        if(l == r) return;
        int m = l + r >> 1;
        build(lson);
        build(rson);
        push_up(rt);
    }

    void update(int L, int R, int v, int l, int r, int rt) {
        if(L <= l && r <= R) {
            lazy[rt] = max(lazy[rt], v);
            Max[rt] = max(Max[rt], lazy[rt]);
            return;
        }
        int m = l + r >> 1;
        push_down(rt);
        if(L <= m) update(L, R, v, lson);
        if(R > m) update(L, R, v, rson);
        push_up(rt);
    }

    int query(int o, int l, int r, int rt) {
        if(l == r) return Max[rt];
        int m = l + r >> 1;
        push_down(rt);
        if(o <= m) return query(o, lson);
        else return query(o, rson);
    }
};

SegTree X, Y;
int n, q;
int ox[N], oy[N];
bool vx[N], vy[N];
char op[N][2];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &q) == 2) {
        memset(vx, false, sizeof vx);
        memset(vy, false, sizeof vy);
        vector<int> xs, ys;
        for(int i = 1; i <= q; ++i) {
            scanf("%d%d%s", ox + i, oy + i, op[i]);
            xs.push_back(ox[i]);
            ys.push_back(oy[i]);
        }
        sort(xs.begin(), xs.end());
        sort(ys.begin(), ys.end());
        xs.resize(unique(xs.begin(), xs.end()) - xs.begin());
        ys.resize(unique(ys.begin(), ys.end()) - ys.begin());
        X.build(1, xs.size(), 1); Y.build(1, ys.size(), 1);

        for(int i = 1; i <= q; ++i) {
            int x = lower_bound(xs.begin(), xs.end(), ox[i]) - xs.begin() + 1;
            int y = lower_bound(ys.begin(), ys.end(), oy[i]) - ys.begin() + 1;
//            pr(x); prln(y);
            if(*op[i] == 'U') {
                if(vx[x]) {
                    puts("0");
                    continue;
                }
                vx[x] = true;
                int Max = X.query(x, 1, xs.size(), 1);
//                pr(Max);
                printf("%d\n", oy[i] - Max);
                int k = lower_bound(ys.begin(), ys.end(), Max) - ys.begin() + 1;
//                pr(k); prln(ox[i]);
                Y.update(k, y, ox[i], 1, ys.size(), 1);
            } else {
                if(vy[y]) {
                    puts("0");
                    continue;
                }
                vy[y] = true;
                int Max = Y.query(y, 1, ys.size(), 1);
//                pr(Max);
                printf("%d\n", ox[i] - Max);
                int k = lower_bound(xs.begin(), xs.end(), Max) - xs.begin() + 1;
//                pr(k); prln(oy[i]);
                X.update(k, x, oy[i], 1, xs.size(), 1);
            }
        }
    }
    return 0;
}
