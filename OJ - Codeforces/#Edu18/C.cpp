//
//  Created by TaoSama on 2017-03-28
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
char s[N];
int f[N][3][2]; //%3, nonzero?
pair<int, int> pre[N][3][2];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%s", s + 1) == 1) {
        n = strlen(s + 1);
        memset(f, 0x3f, sizeof f);
        f[0][0][0] = 0;
        for(int i = 1; i <= n; ++i) {
            for(int j = 0; j < 3; ++j) {
                for(int k = 0; k < 2; ++k) {
                    //delete
                    if(f[i][j][k] > f[i - 1][j][k] + 1) {
                        f[i][j][k] = f[i - 1][j][k] + 1;
                        pre[i][j][k] = {j, k};
                    }
                    int d = s[i] - '0';
                    if(k == 0 && d == 0) continue;
                    int nj = (j * 10 + d) % 3, nk = k | !!d;
                    if(f[i][nj][nk] > f[i - 1][j][k]) {
                        f[i][nj][nk] = f[i - 1][j][k];
                        pre[i][nj][nk] = {j, k};
                    }
                }
            }
        }
        auto pp = [&](int i, int j, int k) {
            printf("f[%d][%d][%d] = %d\n", i, j, k, f[i][j][k]);
        };
//        pp(1, 1, 1);
        int ans = f[n][0][1];
        if(ans == INF) {
            bool zero = false;
            for(int i = 1; i <= n; ++i) zero |= s[i] == '0';
            puts(zero ? "0" : "-1");
            continue;
        }
        string lft;
        for(int i = n, j = 0, k = 1; i; --i) {
            int pj, pk; tie(pj, pk) = pre[i][j][k];
            if(f[i][j][k] == f[i - 1][pj][pk]) lft += s[i];
            j = pj, k = pk;
        }
        reverse(lft.begin(), lft.end());
        puts(lft.c_str());
    }

    return 0;
}
