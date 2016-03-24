//
//  Created by TaoSama on 2015-11-29
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, a[N];
double f[2][N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &m) == 2) {
        int sum = 0;
        for(int i = 1; i <= n; ++i) {
            scanf("%d", a + i);
            sum += a[i];
        }
        if(m == 1) {puts("1"); continue;}

        int cur = 0, nxt = 1;
        memset(f[cur], 0, sizeof f[cur]);
        f[cur][0] = m - 1;
        for(int i = 0; i < n; ++i) {
            memset(f[nxt], 0, sizeof f[nxt]);
            for(int j = 0; j <= i * m; ++j) {
                double p = f[cur][j] / (m - 1);
                f[nxt][j + 1] += p;
                f[nxt][j + m + 1] -= p;
                f[nxt][j + a[i + 1]] -= p;
                f[nxt][j + a[i + 1] + 1] += p;
            }
            for(int j = 1; j <= n * m; ++j)
                f[nxt][j + 1] += f[nxt][j];
            swap(cur, nxt);
        }
        double ans = 0;
        for(int i = 0; i < sum; ++i) ans += f[cur][i];
        printf("%.12f\n", ans + 1);
    }
    return 0;
}
