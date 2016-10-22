//
//  Created by TaoSama on 2016-09-05
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
const int N = 100 + 10, INF = 0x3f3f3f3f, MOD = 1e9;

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
                for(int j = c; j <= m; ++j) {
                    a[i][j] += MOD - delta * a[r][j] % MOD;
                    a[i][j] %= MOD;
                }
                if(!a[i][c]) break;
                neg ^= 1;
                for(int j = c; j <= m; ++j) swap(a[r][j], a[i][j]);
            }
        }
    }
    if(r != n) return 0;

    for(int i = 0; i < r; ++i) ret = ret * a[i][i] % MOD;
    if(neg) ret = (-ret + MOD) % MOD;
    return ret;
}

const int M = 10;

int n, m;
char s[M][M];
int id[M][M];

int d[][2] = { -1, 0, 0, -1, 1, 0, 0, 1};

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; ++i) scanf("%s", s[i]);

    int all = 0;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            if(s[i][j] == '.') id[i][j] = all++;

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(s[i][j] == '*') continue;
            int cur = id[i][j];
            for(int k = 0; k < 4; ++k) {
                int x = i + d[k][0], y = j + d[k][1];
                if(x < 0 || x >= n || y < 0 || y >= m) continue;
                if(s[x][y] == '*') continue;
                int nxt = id[x][y];
                --a[cur][nxt];
                ++a[cur][cur];
            }
        }

    }

    LL ans = gauss(all - 1, all - 1);
    printf("%lld\n", ans);

    return 0;
}
