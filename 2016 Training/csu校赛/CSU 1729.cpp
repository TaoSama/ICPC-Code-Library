//
//  Created by TaoSama on 2016-04-28
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
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
const int N = 1e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, a[N];
int sum[N], f[N][N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) {
            scanf("%d", a + i);
            sum[i] = sum[i - 1] + a[i];
        }

        memset(f, 0x3f, sizeof f);
        for(int i = 1; i <= n; ++i) f[i][i] = f[i + 1][i] = 0;
        for(int i = n; i; --i) {
            for(int j = i + 1; j <= n; ++j) {
                if(a[i] == a[j])
                    f[i][j] = min(f[i][j], f[i + 1][j - 1]);
                else {
                    f[i][j] = min(f[i][j - 1] + 1, f[i + 1][j] + 1);
                    f[i][j] = min(f[i][j], f[i + 1][j - 1] + 2);
                }
            }
        }
        printf("%d\n", f[1][n]);
    }
    return 0;
}
