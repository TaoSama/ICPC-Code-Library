//
//  Created by TaoSama on 2017-06-18
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
double v, u;
double c[N], d[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
//    ios_base::sync_with_stdio(0);

    cin >> n >> v >> u;
    for(int i = 1; i <= n; ++i) cin >> c[i];
    for(int i = 1; i <= n; ++i) cin >> d[i];
    double ans = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            ans += u / (c[i] - (j - 1) * d[i] - v);
        }
    }
    printf("%.3f\n", ans);

    return 0;
}
