//
//  Created by TaoSama on 2017-05-11
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, c, d;
int b[N], p[N], type[N];

struct BIT {
    int n, b[N];
    void init() {
        memset(b, 0, sizeof b);
    }
    void add(int i, int x) {
        for(; i < N; i += i & -i) b[i] = max(b[i], x);
//        for(int i = 0; i < 10; ++i) printf("%d ", b[i]); puts("");
    }
    int sum(int i) {
        int ret = 0;
        for(; i; i -= i & -i) ret = max(ret, b[i]);
        return ret;
    }
} bit;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d%d", &n, &c, &d) == 3) {
        map<pair<int, int>, int> C, D;
        for(int i = 1; i <= n; ++i) {
            char s[10];
            scanf("%d%d%s", b + i, p + i, s);
            type[i] = *s == 'C';
            if(type[i]) C[ {p[i], i}] = b[i];
            else D[ {p[i], i}] = b[i];
        }
        int ans = 0, mxA = 0, mxB = 0, last = 0;
        bit.init();
        for(auto& p : C) {
            if(p.first.first <= c) {
                mxA = max(mxA, p.second);
                int to = c - p.first.first;
                int o = bit.sum(to);
                if(o) ans = max(ans, p.second + o);
                bit.add(p.first.first, p.second);

            }
        }
        bit.init();
        for(auto& p : D) {
            if(p.first.first <= d) {
                mxB = max(mxB, p.second);
                int to = d - p.first.first;
                int o = bit.sum(to);
                if(o) ans = max(ans, p.second + o);
                bit.add(p.first.first, p.second);
            }
        }
//        pr(mxA); prln(mxB);
        if(mxA && mxB) ans = max(ans, mxA + mxB);

        printf("%d\n", ans);
    }

    return 0;
}
