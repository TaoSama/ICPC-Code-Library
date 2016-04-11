//
//  Created by TaoSama on 2015-12-04
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
const int N = 3e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

char s[N];
int n, q, a[N];

struct SegTree {
    int add[N << 2], minv[N << 2];
    void pushUp(int rt) {
        minv[rt] = min(minv[rt << 1], minv[rt << 1 | 1]);
    }
    void pushDown(int rt) {
        if(add[rt]) {
            minv[rt << 1] += add[rt];
            minv[rt << 1 | 1] += add[rt];
            add[rt << 1] += add[rt];
            add[rt << 1 | 1] += add[rt];
            add[rt] = 0;
        }
    }
    void build(int l, int r, int rt) {
        add[rt] = 0; minv[rt] = INF;
        if(l == r) {
            minv[rt] = a[l];
            return;
        }
        int m = l + r >> 1;
        build(l, m, rt << 1);
        build(m + 1, r, rt << 1 | 1);
        pushUp(rt);
    }
    void update(int L, int R, int v, int l, int r, int rt) {
        if(L <= l && r <= R) {
            add[rt] += v;
            minv[rt] += v;
            return;
        }
        pushDown(rt);
        int m = l + r >> 1;
        if(L <= m) update(L, R, v, l, m, rt << 1);
        if(R > m) update(L, R, v, m + 1, r, rt << 1 | 1);
        pushUp(rt);
    }
    int query(int o, int l, int r, int rt) {
        if(l == r) return minv[rt];
        pushDown(rt);
        int m = l + r >> 1;
        if(o <= m) return query(o, l, m, rt << 1);
        else return query(o, m + 1, r, rt << 1 | 1);
    }
    int query(int l, int r, int rt) {
        if(l == r) return l;
        pushDown(rt);
        int m = l + r >> 1;
        if(minv[rt << 1 | 1] >= 2) return query(l, m, rt << 1);
        else return query(m + 1, r, rt << 1 | 1);
    }
} T;

void printTree() {
    for(int i = 1; i <= n; ++i)
        printf("%d ", T.query(i, 1, n, 1)); puts("");
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &q) == 2) {
        scanf("%s", s + 1);
        set<int> rig;
        for(int i = 1; i <= n; ++i) {
            if(s[i] == '(') a[i] = a[i - 1] + 1;
            else {
                rig.insert(i);
                a[i] = a[i - 1] - 1;
            }
//          printf("%d ", a[i]);
        }

        T.build(1, n, 1);
        while(q--) {
            int x; scanf("%d", &x);
            if(s[x] == ')') {
                s[x] = '(';
                rig.erase(x);
                T.update(x, n, 2, 1, n, 1);

//              printTree();
                int p = T.query(1, n, 1) + 1;
                s[p] = ')';
                rig.insert(p);
                T.update(p, n, -2, 1, n, 1);
                printf("%d\n", p);
            } else {
                s[x] = ')';
                rig.insert(x);
                T.update(x, n, -2, 1, n, 1);

                int p = *rig.begin();
                s[p] = '(';
                rig.erase(rig.begin());
                T.update(p, n, 2, 1, n, 1);
                printf("%d\n", p);
            }
        }
    }
    return 0;
}
