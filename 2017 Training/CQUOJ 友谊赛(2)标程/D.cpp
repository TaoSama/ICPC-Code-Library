//
//  Created by TaoSama on 2017-04-09
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
#include <cassert>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

struct Operation {
    int type, tim, id;
    int l, r, v;
    bool operator<(const Operation& rhs) const {
        if(tim != rhs.tim) return tim < rhs.tim;
        if(type != rhs.type) return type < rhs.type;
        return id < rhs.id;
    }
};

int n, m, k, q;
typedef long long LL;
pair<LL, LL> ans[N];

struct Node {
    int l, r;
    LL val, addv, setv;
    Node() {}
    Node(int l, int r): l(l), r(r) {}
    void clear() {
        val = addv = 0;
        setv = -1;
    }
    void add(LL v) {
        val += v * (r - l + 1);
        addv += v;
    }
    void set(LL v) {
        val = v * (r - l + 1);
        setv = v;
        addv = 0;
    }
} dat[N << 2];

void up(int rt) {
    dat[rt].val = dat[rt << 1].val + dat[rt << 1 | 1].val;
}
void down(int rt) {
    LL& setv = dat[rt].setv;
    int ls = rt << 1, rs = ls | 1;
    if(~setv) {
        dat[ls].set(setv);
        dat[rs].set(setv);
        setv = -1;
    }
    LL& addv = dat[rt].addv;
    if(addv) {
        dat[ls].add(addv);
        dat[rs].add(addv);
        addv = 0;
    }
}

void build(int l, int r, int rt) {
    dat[rt] = Node(l, r);
    dat[rt].clear();
    if(l == r) return;
    int m = l + r >> 1;
    build(l, m, rt << 1);
    build(m + 1, r, rt << 1 | 1);
}

LL tmp;
void update(int L, int R, int op, int v, int rt) {
    if(L <= dat[rt].l && dat[rt].r <= R) {
        if(op == 1) dat[rt].add(v);
        else if(op == 2) dat[rt].set(v);
        else tmp += dat[rt].val;
        return;
    }
    down(rt);
    int m = (dat[rt].l + dat[rt].r) >> 1;
    if(L <= m) update(L, R, op, v, rt << 1);
    if(R > m) update(L, R, op, v, rt << 1 | 1);
    up(rt);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d%d%d", &n, &m, &k, &q) == 4) {
        vector<Operation> queries; queries.reserve(m + k + q);
        for(int i = 1; i <= m; ++i) {
            int l, len, v; scanf("%d%d%d", &l, &len, &v);
            queries.push_back({1, i, i, l, l + len - 1, v});
        }

        for(int i = 1; i <= k; ++i) {
            int tim, l, len; scanf("%d%d%d", &tim, &l, &len);
            queries.push_back({2, tim, i, l, l + len - 1, -1});
        }

        for(int i = 1; i <= q; ++i) {
            int tim; scanf("%d", &tim);
            queries.push_back({3, tim - 1, i, -1, -1, -1});
        }

        build(1, n, 1);
        sort(queries.begin(), queries.end());

        LL sum = 0;
        for(const auto& q : queries) {
//          cout << q.type << ' ' << q.tim << ' ';
//          cout << q.l << ' ' << q.r << ' ' << q.v << endl;
            if(q.type == 1) {
                update(q.l, q.r, q.type, q.v, 1);
            } else if(q.type == 2) {
                tmp = 0;
                update(q.l, q.r, 3, -1, 1);
                sum += tmp;
                update(q.l, q.r, q.type, 0, 1);
            } else {
                ans[q.id] = {sum, dat[1].val};
            }
        }
        for(int i = 1; i <= q; ++i) {
            printf("%lld %lld\n", ans[i].first, ans[i].second);
        }

        //1. range addition
        //2. range value setting  => 0
        //3. query
    }

    return 0;
}
