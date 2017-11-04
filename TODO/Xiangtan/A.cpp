//
//  Created by TaoSama on 2017-05-16
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 500 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;
LL a[N][N], b[N][N];
LL gauss(int n, int m) {
    LL ret = 1, neg = 0;
    int r = 0, c = 0;
    for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			b[i][j] = i == j;
    for(; r < n && c < m; ++r, ++c) {
        int p = r;
        for(; p < n; ++p) if(a[p][c]) break;
        if(p == n) {--r; continue;}
        if(p != r) {
            neg ^= 1;
            for(int i = c; i < m; ++i) {
				swap(a[p][i], a[r][i]);
				swap(b[p][i], b[r][i]);
            }
        }

        //eliminate coefficient
        for(int i = r + 1; i < n; ++i) {
            while(a[i][c]) {
                LL delta = a[i][c] / a[r][c];
                for(int j = c; j < m; ++j) {
                    a[i][j] += MOD - delta * a[r][j] % MOD;
                    a[i][j] %= MOD;
                }
                if(!a[i][c]) break;
                neg ^= 1;
                for(int j = c; j < m; ++j) swap(a[r][j], a[i][j]);
            }
        }
    }
    if(r != n) return 0;
    for(int i = 0; i < r; ++i) ret = ret * a[i][i] % MOD;
    if(neg) ret = (-ret + MOD) % MOD;
    return ret;
}

LL myrand() {
    return (rand() << 16) + rand();
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i) {
            if(i == 1) {a[i][j] = myrand(); continue;}
            for(int j = 1; j <= n; ++j) {
                scanf("%lld", a[i] + j);
            }
        }


    }

    return 0;
}
