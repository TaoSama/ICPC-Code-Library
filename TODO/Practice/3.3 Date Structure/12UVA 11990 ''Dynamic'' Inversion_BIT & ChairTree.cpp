//
//  Created by TaoSama on 2015-07-13
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
const int M = N * 35;

int n, q, p[N];
int root[N << 1], sum[M << 1], ls[M << 1], rs[M << 1], sz;
vector<int> pL, pR, tL, tR;

void insert(int o, int v, int l, int r, int pre, int &rt) {
    rt = ++sz; sum[rt] = sum[pre] + v;
    if(l == r) return;
    ls[rt] = ls[pre]; rs[rt] = rs[pre];

    int m = l + r >> 1;
    if(o <= m) insert(o, v, l, m, ls[pre], ls[rt]);
    else insert(o, v, m + 1, r, rs[pre], rs[rt]);
}

void modify(int o, int v, int l, int r, int& rt) {
    if(!rt) rt = ++sz, sum[rt] = ls[rt] = rs[rt] = 0;
    sum[rt] += v;
    if(l == r) return;

    int m = l + r >> 1;
    if(o <= m) modify(o, v, l, m, ls[rt]);
    else modify(o, v, m + 1, r, rs[rt]);
}

int query(int L, int R, int l, int r, vector<int> pL, vector<int> pR) {
    int m = l + r >> 1, ret = 0;
//    pr(L); pr(R); pr(l); pr(r); prln(pR[1]);

    if(L <= l && r <= R) {
        for(int i = 0; i < pL.size(); ++i) ret -= sum[pL[i]];
        for(int i = 0; i < pR.size(); ++i) ret += sum[pR[i]];
        return ret;
    }

    if(L <= m) {
        tL = pL; tR = pR;
        for(int i = 0; i < tL.size(); ++i) tL[i] = ls[tL[i]];
        for(int i = 0; i < tR.size(); ++i) tR[i] = ls[tR[i]];
        ret += query(L, R, l, m, tL, tR);
//        pr(tR[1]); prln(pR[1]);
    }
    if(R > m) {
//        pr(pR[1]);
        tL = pL; tR = pR;
        for(int i = 0; i < tL.size(); ++i) tL[i] = rs[tL[i]];
        for(int i = 0; i < tR.size(); ++i) tR[i] = rs[tR[i]];
//        prln(pR[1]);
        ret += query(L, R, m + 1, r, tL, tR);
    }
    return ret;
}

void query(int o, int l, int r, int rt, int z) {
    pr(l); pr(r); pr(rt); prln(sum[rt]);
    if(l == r) return;
    int m = l + r >> 1;
    if(o <= m) query(o, l, m, ls[rt], 1);
    else query(o, m + 1, r, rs[rt], 1);
}

int b[N];

void add(int i, int v) {
    for(; i <= n; i += i & -i) b[i] += v;
}

int getSum(int i) {
    int ret = 0;
    for(; i; i -= i & -i) ret += b[i];
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &q) == 2) {
        sz = 0;
        memset(root, 0, sizeof root);
        memset(b, 0, sizeof b);

        long long ans = 0;
        for(int i = 1; i <= n; ++i) {
            int x; scanf("%d", &x);
            p[x] = i;
            ans += i - 1 - getSum(x); add(x, 1);
            insert(x, 1, 1, n, root[i - 1 + n], root[i + n]);
        }

//        query(3, 1, n, root[5 + n], 1); cout << endl;
//        query(4, 1, n, root[5 + n], 1);
//        for(int i = 1; i <= n; ++i) {
//            for(int j = 1; j <= n; ++j) query(j, 1, n, root[i + n], 1), cout << endl;;
//            cout << endl;
//        } cout << endl;

        while(q--) {
            int x; scanf("%d", &x);
            printf("%lld\n", ans);
            if(ans && q) {
                if(p[x] != 1 && x != n) { // [1, p[x]-1]中比x大的数的个数
                    pL.clear(); pR.clear();
                    pR.push_back(root[p[x] - 1 + n]);
                    for(int i = p[x] - 1; i; i -= i & -i) pR.push_back(root[i]);
//                    int t = ans;
                    ans -= query(x + 1, n, 1, n, pL, pR);
//                    cout << "big: " << t - ans << endl;
                }
                if(p[x] != n && x != 1) { //[p[x]+1, n]比x小的数的个数
                    pL.clear(); pR.clear();
                    pL.push_back(root[p[x] + n]);
                    pR.push_back(root[n + n]);
                    for(int i = p[x]; i; i -= i & -i) pL.push_back(root[i]);
                    for(int i = n; i; i -= i & -i) pR.push_back(root[i]);
//                    int t = ans;
                    ans -= query(1, x - 1, 1, n, pL, pR);
//                    cout << "less: " << t - ans << endl;
                }
//                cout << endl;
            }
            for(int i = p[x]; i <= n; i += i & -i)
                modify(x, -1, 1, n, root[i]);
        }
    }
    return 0;
}
