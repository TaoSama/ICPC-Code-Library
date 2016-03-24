//
//  Created by TaoSama on 2015-06-13
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
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 5e5 + 10;

int n, q, cnt, ll, rr;
long long sum[N << 2], add[N << 2];
long long ans[N];
bool ok = false;

#define root 1, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

void push_up(int rt) {
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void push_down(int rt, int m) {
    if(add[rt]) {
        sum[rt << 1] += add[rt] * (m - (m >> 1));
        sum[rt << 1 | 1] += add[rt] * (m >> 1);
        add[rt << 1] += add[rt];
        add[rt << 1 | 1] += add[rt];
        add[rt] = 0;
    }
}

void build(int l, int r, int rt) {
    add[rt] = 0;
    if(l == r) {
        scanf("%I64d", &sum[rt]);
        return;
    }
    int m = l + r >> 1;
    build(lson);
    build(rson);
    push_up(rt);
}

void update(int L, int R, int v, int l, int r, int rt) {
    if(L <= l && r <= R) {
        sum[rt] += 1LL * v * (r - l + 1);
        add[rt] += v;
        return;
    }
    push_down(rt, r - l + 1);
    int m = l + r >> 1;
    if(L <= m) update(L, R, v, lson);
    if(R > m) update(L, R, v, rson);
    push_up(rt);
}

void query_l(int x, int l, int r, int rt) {
    if(l == r) {
        ++ cnt;
//        cout << cnt << ' ' << sum[rt] << ' ' << x << endl;
//        if(sum[rt] == x) {
//            ll = cnt;
//            throw 1;
//        }
		if(sum[rt] == x) ok = true;
        ans[cnt] = sum[rt];
        return;
    }
    push_down(rt, r - l + 1);
    int m = l + r >> 1;
    query_l(x, lson);
    query_l(x, rson);
}

void query_r(int x, int l, int r, int rt) {
    if(l == r) {
        --cnt;
//        cout << cnt << ' ' << sum[rt] << ' ' << x << endl;
        if(sum[rt] == x) {
            rr = cnt;
            throw 1;
        }
        return;
    }
    push_down(rt, r - l + 1);
    int m = l + r >> 1, ans;
    query_r(x, rson);
//    if(~ans) return ans;
    query_r(x, lson);
//    if(~ans) return ans;
//    return -1;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &q) == 2) {
        build(root);
        int op, x, y, z;
        while(q--) {
            scanf("%d", &op);
            if(op == 1) {
                scanf("%d%d%d", &x, &y, &z);
                update(x, y, z, root);
            } else {
                scanf("%d", &y);
                cnt = 0;
                ll = rr = -1;
//                try {
//                    query_l(y, root);
//                } catch(int) {}
//                cnt = n + 1;
//                try {
//                    query_r(y, root);
//                } catch(int) {}
				ok = false;
                query_l(y, root);
                if(!ok) {
					puts("-1");
					continue;
                }
                for(int i = 1; i <= n; ++i) {
                    if(ans[i] == y) {
                        ll = i;
                        break;
                    }
                }
                for(int i = n; i >= 1; --i) {
                    if(ans[i] == y) {
                        rr = i;
                        break;
                    }
                }
//                cout << ll << ' ' << rr << endl;
                if(ll == -1 && rr == - 1) puts("-1");
                else printf("%d\n", rr - ll);
            }
        }
    }
    return 0;
}
