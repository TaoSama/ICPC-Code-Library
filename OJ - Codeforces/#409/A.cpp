//
//  Created by TaoSama on 2017-04-16
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, p;
int a[N], b[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &p) == 2) {
        long long sum = 0;
        for(int i = 1; i <= n; ++i) {
            scanf("%d%d", a + i, b + i);
            sum += a[i];
        }
        if(p >= sum) {
            puts("-1");
            continue;
        }
        double l = 0, r = 1e18;
        static auto get = [&](double x) {
            double sum = 0;
            for(int i = 1; i <= n; ++i) {
                sum += max(0.0, (a[i] * x - b[i]) / p);
                if(sum > x) return false;
            }
            return true;
        };
        for(int i = 1; i <= 200; ++i) {
            double m = (l + r) / 2;
            if(get(m)) l = m;
            else r = m;
        }
        printf("%.20f\n", l);
    }

    return 0;
}
