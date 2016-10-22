//
//  Created by TaoSama on 2016-09-06
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
const int N = 15 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;
LL a[N][N], ans[N];
bool isFreeX[N];

LL gauss(int n, int m) {
    for(int i = 0; i < m; ++i) isFreeX[i] = false;
    LL ret = 1, neg = 0;

    int r = 0, c = 0;
    for(; r < n && c < m; ++r, ++c) {
        int p = r;
        for(; p < n; ++p) if(a[p][c]) break;
        if(p == n) {--r; isFreeX[c] = true; continue;}
        if(p != r) {
            neg ^= 1;
            for(int i = c; i <= m; ++i) swap(a[p][i], a[r][i]);
        }

        //eliminate coefficient
        for(int i = r + 1; i < n; ++i) {
            while(a[i][c]) {
                LL delta = a[i][c] / a[r][c];
                for(int j = c; j <= m; ++j)
                    a[i][j] -= delta * a[r][j];
                if(!a[i][c]) break;
                neg ^= 1;
                for(int j = c; j <= m; ++j) swap(a[r][j], a[i][j]);
            }
        }
    }
    if(r != n) return 0;

    for(int i = 0; i < r; ++i) ret *= a[i][i];
    if(neg) ret = -ret;
    return ret;
}

int n, m;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);

        memset(a, 0, sizeof a);
        for(int i = 1; i <= m; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            --u, --v;
            a[u][v] = a[v][u] = -1;
            ++a[u][u], ++a[v][v];
        }

        printf("%lld\n", gauss(n - 1, n - 1));
    }

    return 0;
}
