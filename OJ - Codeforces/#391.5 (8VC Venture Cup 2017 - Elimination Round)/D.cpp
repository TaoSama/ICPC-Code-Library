//
//  Created by TaoSama on 2017-01-16
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
const int N = 1e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;

struct BIT {
    int n, b[N];
    void init(int _n) {
        n = _n;
        memset(b, 0, sizeof b);
    }
    void add(int i, int v) {
        for(; i <= n; i += i & -i) b[i] += v;
    }
    void add(int l, int r, int v) {
        add(l, v);
        add(r + 1, -v);
    }
    int sum(int i) {
        int ret = 0;
        for(; i; i -= i & -i) ret += b[i];
        return ret;
    }
} bit;

int n, k;

void norm(int& x) {if(x > n) x -= n; if(x <= 0) x += n; }

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &k) == 2) {
        if(k > n / 2) k = n - k;
        bit.init(n);
        int s = 1, last = 0;
        long long ans = 1;
        for(int i = 1; i <= n; ++i) {
            int ns = s + k; norm(ns);
            int cur = bit.sum(ns);
            ans += cur + last + 1;
            int l = s + 1, r = ns - 1; norm(l); norm(r);
//            pr(ns); pr(last); pr(cur); prln(ans);
            s = ns; last = cur;
//            pr(l); prln(r); prln(bit.sum(5));

            if(l > r) {
                bit.add(l, n, 1);
                bit.add(1, r, 1);
            } else bit.add(l, r, 1);

            printf("%I64d%c", ans, " \n"[i == n]);
        }
    }

    return 0;
}
