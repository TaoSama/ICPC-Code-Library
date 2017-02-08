//
//  Created by TaoSama on 2017-01-31
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
char a[100][100];
int f[100][1 << 3];

int get(char c) {
    if(isdigit(c)) return 0;
    else if(islower(c)) return 1;
    return 2;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &m) == 2) {
        for(int i = 1; i <= n; ++i) scanf("%s", a[i] + 1);
        for(int i = 1; i <= n; ++i) {
            int s = 0; f[i][s] = 0;
            for(int j = 1; j < 1 << 3; ++j) f[i][j] = 100;
            for(int j = 1; j <= m; ++j) {
                s = 1 << get(a[i][j]);
                f[i][s] = min(f[i][s], j - 1);
            }
            for(int j = 1; j <= m; ++j) {
                s = 1 << get(a[i][m - j + 1]);
                f[i][s] = min(f[i][s], j);
            }
        }
//        pr(f[1][1]); pr(f[2][4]); prln(f[3][2]);
//        prln(f[1][1] + f[2][4] + f[3][2]);

        int ans = INF;
        for(int i = 1; i <= n; ++i) {
            for(int s1 = 0; s1 < 1 << 3; ++s1) {
                if(s1 == 7) ans = min(ans, f[i][s1]);
                for(int j = i + 1; j <= n; ++j) {
                    for(int s2 = 0; s2 < 1 << 3; ++s2) {
                        if((s1 | s2) == 7) ans = min(ans, f[i][s1] + f[j][s2]);
                        for(int k = j + 1; k <= n; ++k) {
                            for(int s3 = 0; s3 < 1 << 3; ++s3) {
                                if((s1 | s2 | s3) == 7)
                                    ans = min(ans, f[i][s1] + f[j][s2] + f[k][s3]);
                            }
                        }
                    }
                }
            }
        }
        printf("%d\n", ans);

    }

    return 0;
}
