//
//  Created by TaoSama on 2015-09-15
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
const int N = 5e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

#define root 1, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

typedef long long LL;

LL sum[N << 2], pre[N << 2], sub[N << 2], suf[N << 2];
int preR[N << 2], subL[N << 2], subR[N << 2], sufL[N << 2];

void push_up(int rt) {
    int ls = rt << 1, rs = rt << 1 | 1;
    sum[rt] = sum[ls] + sum[rs];
    LL Max, l, r;

    //prefix
    Max = pre[ls], r = preR[ls];
    if(pre[ls] < sum[ls] + pre[rs]) {
        Max = sum[ls] + pre[rs];
        r = preR[rs];
    }
    pre[rt] = Max, preR[rt] = r;
    //suffix
    Max = suf[rs], l = sufL[rs];
    if(suf[rs] <= sum[rs] + suf[ls]) {
        Max = sum[rs] + suf[ls];
        l = sufL[ls];
    }
    suf[rt] = Max, sufL[rt] = l;
    //sub
    Max = sub[ls], l = subL[ls], r = subR[ls];
    if(Max < suf[ls] + pre[rs]) {
        Max = suf[ls] + pre[rs];
        l = sufL[ls], r = preR[rs];
    }
    if(Max < sub[rs]) {
        Max = sub[rs];
        l = subL[rs], r = subR[rs];
    }
    sub[rt] = Max, subL[rt] = l, subR[rt] = r;
}

void build(int l, int r, int rt) {
    if(l == r) {
        scanf("%lld", &sum[rt]);
        pre[rt] = sub[rt] = suf[rt] = sum[rt];
        preR[rt] = subL[rt] = subR[rt] = sufL[rt] = l;
        return;
    }
    int m = l + r >> 1;
    build(lson);
    build(rson);
    push_up(rt);
}

struct Node {
    LL sum, pre, sub, suf;
    int preL, preR, subL, subR, sufL, sufR;
};

Node query(int L, int R, int l, int r, int rt) {
    if(L <= l && r <= R) {
        Node t;
        t.sum = sum[rt]; t.pre = pre[rt];
        t.sub = sub[rt]; t.suf = suf[rt];
        t.preL = l; t.preR = preR[rt];
        t.subL = subL[rt]; t.subR = subR[rt];
        t.sufL = sufL[rt]; t.sufR = r;
        return t;
    }
    int m = l + r >> 1, x = 0, y = 0;
    Node ll, rr, ret;
    if(L <= m) ll = query(L, R, lson), x = 1;
    if(R > m) rr = query(L, R, rson), y = 1;
    if(x && !y) ret = ll;
    else if(!x && y) ret = rr;
    else {
        ret.sum = ll.sum + rr.sum;
        //prefix
        ret.pre = ll.pre, ret.preL = ll.preL, ret.preR = ll.preR;
        if(ret.pre < ll.sum + rr.pre) {
            ret.pre = ll.sum + rr.pre;
            ret.preL = ll.preL; ret.preR = rr.preR;
        }
        //suffix
        ret.suf = rr.suf, ret.sufL = rr.sufL, ret.sufR = rr.sufR;
        if(ret.suf <= rr.sum + ll.suf) {
            ret.suf = rr.sum + ll.suf;
            ret.sufL = ll.sufL; ret.sufR = rr.sufR;
        }
        //sub
        ret.sub = ll.sub, ret.subL = ll.subL, ret.subR = ll.subR;
        if(ret.sub < ll.suf + rr.pre) {
            ret.sub = ll.suf + rr.pre;
            ret.subL = ll.sufL; ret.subR = rr.preR;
        }
        if(ret.sub < rr.sub) {
            ret.sub = rr.sub;
            ret.subL = rr.subL; ret.subR = rr.subR;
        }
    }
    return ret;
}

int n, q;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int kase = 0;
    while(scanf("%d%d", &n, &q) == 2) {
        build(root);
        printf("Case %d:\n", ++kase);
        while(q--) {
            int l, r; scanf("%d%d", &l, &r);
            Node ans = query(l, r, root);
            printf("%d %d\n", ans.subL, ans.subR);
        }
    }
    return 0;
}
