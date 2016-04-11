//
//  Created by TaoSama on 2016-03-26
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
const int N = 1.1e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

string str;

struct Node {
    int l, r;
    int sum;
    Node() {}
    Node(int l, int r): l(l), r(r) {}
    int len() {
        return r - l + 1;
    }
    void set(int v) {
        if(v == -1) return;
        if(v == 2) sum = len() - sum;
        else sum = len() * v;
    }
} dat[N << 2];

int tag[N << 2];

void pushUp(int rt) {
    dat[rt].sum = dat[rt << 1].sum + dat[rt << 1 | 1].sum;
}

void combineTag(int fa, int& son) {
    if(fa == 2) {
        if(son == -1) son = 2;
        else if(son == 2) son = -1;
        else son ^= 1; // switch 0, 1
    } else son = fa; //set 0, 1
}

void pushDown(int rt) {
    if(tag[rt] == -1) return;

    int ls = rt << 1, rs = ls | 1;
    dat[ls].set(tag[rt]);
    dat[rs].set(tag[rt]);
    combineTag(tag[rt], tag[ls]);
    combineTag(tag[rt], tag[rs]);

    tag[rt] = -1;
}

void build(int l, int r, int rt) {
    dat[rt] = Node(l, r);
    tag[rt] = -1;
    if(l == r) {
        dat[rt].sum = str[l] - '0';
        return;
    }
    int m = l + r >> 1;
    build(l, m, rt << 1);
    build(m + 1, r, rt << 1 | 1);
    pushUp(rt);
}

void update(int L, int R, int v, int rt) {
    if(L <= dat[rt].l && dat[rt].r <= R) {
        dat[rt].set(v);
        combineTag(v, tag[rt]);
        return;
    }
    pushDown(rt);
    int m = dat[rt].l + dat[rt].r >> 1;
    if(L <= m) update(L, R, v, rt << 1);
    if(R > m) update(L, R, v, rt << 1 | 1);
    pushUp(rt);
}

int query(int L, int R, int rt) {
    if(L <= dat[rt].l && dat[rt].r <= R) return dat[rt].sum;
    pushDown(rt);
    int m = dat[rt].l + dat[rt].r >> 1;
    int ret = 0;
    if(L <= m) ret += query(L, R, rt << 1);
    if(R > m) ret += query(L, R, rt << 1 | 1);
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        str.clear();
        int m; scanf("%d", &m);
        while(m--) {
            int cnt;
            char buf[105]; scanf("%d%s", &cnt, buf);
            while(cnt--) str += buf;
        }
        build(0, str.size() - 1, 1);

        int q; scanf("%d", &q);
        int qs = 0;
        static int kase = 0;
        printf("Case %d:\n", ++kase);
        while(q--) {
            char op[2]; int a, b; scanf("%s%d%d", op, &a, &b);
            if(*op == 'F') update(a, b, 1, 1);
            else if(*op == 'E') update(a, b, 0, 1);
            else if(*op == 'I') update(a, b, 2, 1);
            else printf("Q%d: %d\n", ++qs, query(a, b, 1));
        }
    }
    return 0;
}
