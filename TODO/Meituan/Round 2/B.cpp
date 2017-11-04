//
//  Created by TaoSama on 2017-06-18
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 50 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int f[N][N][N][N];
int n, m;
char a[N], b[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        memset(f, 0, sizeof f);
        scanf("%s%s", a + 1, b + 1);
        n = strlen(a + 1), m = strlen(b + 1);
        int ans = 1;
        for(int i = 0; i <= n; ++i) {
            for(int l1 = 1; l1 <= n - i + 1; ++l1) {
                for(int j = 0; j <= m; ++j) {
                    for(int l2 = 1; l2 <= m - j + 1; ++l2) {
                        int r1 = l1 + i - 1, r2 = l2 + j - 1;
                        int& cur = f[l1][r1][l2][r2];
                        if(i == 0 && j == 0) continue;
                        if(i + j == 1) cur = 1;
                        else {
                            cur = -INF;
                            if(l1 < r1 && a[l1] == a[r1])
                                cur = max(cur, f[l1 + 1][r1 - 1][l2][r2] + 2);
                            if(l2 < r2 && b[l2] == b[r2])
                                cur = max(cur, f[l1][r1][l2 + 1][r2 - 1] + 2);
                            if(l1 <= r1 && l2 <= r2) {
                                if(a[l1] == b[r2])
                                    cur = max(cur, f[l1 + 1][r1][l2][r2 - 1] + 2);
                                if(a[r1] == b[l2])
                                    cur = max(cur, f[l1][r1 - 1][l2 + 1][r2] + 2);
                            }
                            ans = max(ans, cur);
                        }
                    }
                }
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}
