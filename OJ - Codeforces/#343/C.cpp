//
//  Created by TaoSama on 2016-02-22
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:1024000000,1024000000")
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

int n, m;
char s[N];
int f[2005][2005];

void add(int& x, int y) {
    if((x += y) >= MOD) x -= MOD;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d%s", &n, &m, s + 1) == 3) {
        f[0][0] = 1;
        for(int i = 1; i <= n - m; ++i) {
            for(int j = 0; j <= i; ++j) {
                if(j - 1 >= 0) add(f[i][j], f[i - 1][j - 1]); //(
                if(j + 1 <= i) add(f[i][j], f[i - 1][j + 1]); //(
            }
        }

        int b = 0, minB = INF;
        for(int i = 1; i <= m; ++i) {
            if(s[i] == '(') ++b;
            else --b;
            minB = min(minB, b);
        }

        int ans = 0;
        for(int i = 0; i <= n - m; ++i)
            for(int j = 0; j <= i; ++j)
                if(j + minB >= 0 && j + b <= min(i + m, n - m - i))
                    add(ans, 1LL * f[i][j] * f[n - m - i][j + b] % MOD);
        printf("%d\n", ans);
    }
    return 0;
}
