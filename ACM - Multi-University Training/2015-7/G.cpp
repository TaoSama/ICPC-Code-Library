//
//  Created by TaoSama on 2016-05-09
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
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
char s[N];
int f[N][2]; //binary from high bit to low bit

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%s", s + 1);
        n = strlen(s + 1);

        memset(f, 0xc0, sizeof f);
        f[0][0] = 0;
        for(int i = 1; i <= n; ++i) {
            int w; scanf("%d", &w);
            if(s[i] == '0') f[i][0] = max(f[i - 1][0], f[i - 1][1] + w);
            else if(s[i] == '1') f[i][1] = max(f[i - 1][1], f[i - 1][0] + w);
            else {
                f[i][0] = max(f[i - 1][0], f[i - 1][1] + w);
                f[i][1] = max(f[i - 1][1], f[i - 1][0] + w);
            }
        }
        int ans = max(f[n][0], f[n][1]);
        static int kase = 0;
        printf("Case #%d: %d\n", ++kase, ans);
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
