//
//  Created by TaoSama on 2016-09-29
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;

LL n;
int kase;
int digit[70], f[70][4][2][2], g[70][4][2];

inline add(int& x, int y) {
    if((x += y) >= MOD) x -= MOD;
}

int dfs1(int x, int msk, int d1, int d2, int e){
    if(x == -1) {
            prln(e);
            return e;
    }
    int& ret = f[x][msk][d1][d2];

    if(~ret) return ret;

    ret = 0;
    int to[2];
    for(int i = 0; i < 2; ++i) to[i] = (msk >> i & 1) ? 1 : n >> x & 1;
    for(int a = 0; a <= to[0]; ++a) {
        for(int b = 0; b <= to[1]; ++b) {
            int newMsk = msk;
            if(a != to[0]) newMsk |= 1 << 0;
            if(b != to[1]) newMsk |= 1 << 1;
            add(ret, dfs1(x - 1, newMsk, a, b, e + a + b));
        }
    }
    return ret;
}

int dfs2(int x, int msk, int lcp, int e) {
    if(x == -1) return 1;
    int& ret = g[x][msk][lcp];

    if(~ret) return ret;

    ret = 0;
    int to[2];
    for(int i = 0; i < 2; ++i) to[i] = (msk >> i & 1) ? 1 : n >> x & 1;
    for(int a = 0; a <= to[0]; ++a) {
        for(int b = 0; b <= to[1]; ++b) {
            int newSmall = small, newE = e;
            if(!newSmall) {
                if(a > b) continue;
                else if(a < b) newSmall = 1;
                else newE -= 2 * a;
            }
//            pr(x); pr(a); pr(b); pr(newSmall); pr(newMatch); prln(tot+a+b);
            int newMsk = msk;
            if(a != to[0]) newMsk |= 1 << 0;
            if(b != to[1]) newMsk |= 1 << 1;
            add(ret, dfs2(x - 1, newMsk, newLcp, e + a + b));
        }
    }
    return ret;
}

struct BIT {
    int n, b[N];
    void init(int _n) {
        n = _n;
        memset(b, 0, sizeof b);
    }
    void add(int x, int y) {
        for(; x; x -= x & -x) b[x] += y;
    }
    int get() {
        int ret = 0;
        for(int i = 1; i <= n; ++i) ret += abs(b[i]);
        return ret;
    }
} bit;

int calc(){
    memset(f, -1, sizeof f);
    memset(g, -1, sizeof g);
    int totOne = dfs1(2, 0, 0, 0, 0);
    totOne = 1LL * totOne * totOne % MOD;
    int lcpOne = dfs2(2, 0, 0, 0);
    pr(totOne); prln(lcpOne);
    int ans = totOne - lcpOne;
    if(ans < 0) ans += MOD;
    return ans;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

//    int T = 1e4; cout << T << endl;
//    while(T--) cout << LL(1e18) << endl;
//    return 0;

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%I64d", &n);
//        int a = 0;
//        for(int i = 1; i <= n; ++i) {
//            for(int j = 1; j <= i; ++j) {
//                bit.init(n);
//                bit.add(j - 1, -1);
//                bit.add(i, 1);
//                a += bit.get();
//            }
//        }
//        prln(a);

        ++kase;
        printf("%d\n", calc());
    }

    return 0;
}
