//
//  Created by TaoSama on 2017-02-27
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
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e2 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
char s[N];
int f[N][N][N / 2][3];

void getMax(int& x, int y) {
    if(x < y) x = y;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        vector<int> p(1, 0);
        scanf("%d%d%s", &n, &m, s + 1);  m >>= 1;
        for(int i = 1; i <= n; ++i) if(s[i] == '2') p.push_back(i);
        int c2 = p.size() - 1, c3 = n - c2;

        for(int i = 0; i <= c2; ++i)
            for(int j = 0; j <= c3; ++j)
                for(int k = 0; k <= m; ++k)
                    for(int z = 0; z < 3; ++z)
                        f[i][j][k][z] = -INF;
        f[0][0][0][2] = 0;
        for(int i = 0; i <= c2; ++i) {
            for(int j = 0; j <= c3; ++j) {
                for(int k = 0; k <= m; ++k) {
                    for(int z = 0; z < 3; ++z) {
                        if(f[i][j][k][z] < 0) continue;
                        if(i < c2) {
                            int nk = k + abs(i + j + 1 - p[i + 1]);
                            if(nk <= m) getMax(f[i + 1][j][nk][0], f[i][j][k][z]);
                        }
                        if(j < c3) {
                            int nz = z, one = 0;
                            if(nz != 2) {
                                if(++nz == 2) ++one;
                            }
                            getMax(f[i][j + 1][k][nz], f[i][j][k][z] + one);
                        }
                    }
                }
            }
        }

        int ans = 0;
        for(int k = 0; k <= m; ++k)
            for(int z = 0; z < 3; ++z)
                getMax(ans, f[c2][c3][k][z]);
        printf("%d\n", ans);
    }

    return 0;
}
