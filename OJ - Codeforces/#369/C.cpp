//
//  Created by TaoSama on 2016-08-29
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
const int N = 100 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;
int n, m, K;
int c[N], p[N][N];
LL f[N][N][N];

inline void getMin(LL& x, LL y) {
    if(x > y) x = y;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    cin >> n >> m >> K;
    for(int i = 1; i <= n; ++i) cin >> c[i];
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            cin >> p[i][j];

    memset(f, 0x3f, sizeof f);
    if(c[1]) f[1][c[1]][1] = 0;
    else {
        for(int i = 1; i <= m; ++i) f[1][i][1] = p[1][i];
    }

    for(int i = 1; i < n; ++i) {
        for(int j = 1; j <= m; ++j) {
            for(int k = 1; k <= K; ++k) {
                if(c[i + 1]) {
                    int l = c[i + 1];
                    if(j != l) getMin(f[i + 1][l][k + 1], f[i][j][k]);
                    else getMin(f[i + 1][l][k], f[i][j][k]);
                } else {
                    for(int l = 1; l <= m; ++l) {
                        if(j != l) getMin(f[i + 1][l][k + 1], f[i][j][k] + p[i + 1][l]);
                        else getMin(f[i + 1][l][k], f[i][j][k] + p[i + 1][l]);
                    }
                }
            }
        }
    }

    LL ans = 1LL * INF * 200;
    for(int i = 1; i <= m; ++i) getMin(ans, f[n][i][K]);
    if(ans == 1LL * INF * 200) ans = -1;
    cout << ans << endl;
    return 0;
}
