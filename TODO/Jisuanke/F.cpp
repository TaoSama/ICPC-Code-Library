//
//  Created by TaoSama on 2017-06-10
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 18, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;
int f[N + 1][1 << N];
bool vis[N][1 << N];
int n, k, a[N];

inline void add(int& x, int y) {
    if((x += y) >= MOD) x -= MOD;
//  x += y;
//  x %= MOD;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; ++i) scanf("%d", a + i);

    memset(f, 0, sizeof f);
    int tot = (1 << n) - 1;
    f[0][tot] = vis[0][tot] = 1;
    int ans = 0;
    int v[20];
    for(int i = 0; i < n; ++i) {
        for(int s = 0; s <= tot; ++s) {
            if(!vis[i][s]) continue;
            int sz = 0;
            for(int j = 0; j < n; ++j) if(s >> j & 1) v[sz++] = j;
            for(int l = 0; l < sz; ++l) {
                int gcd = a[v[l]], c = 1 << v[l];
                if(gcd >= k) {
                    add(f[i + 1][s ^ c], f[i][s]);
                    vis[i + 1][s ^ c] = 1;
                }
                for(int r = l + 1; r < sz; ++r) {
                    gcd = __gcd(gcd, a[v[r]]);
                    if(gcd < k) break;
                    c |= 1 << v[r];
                    vis[i + 1][s ^ c] = 1;
                    add(f[i + 1][s ^ c], f[i][s]);
//                    if(c == tot) {
//                      printf("gcd = %d\n", gcd);
//                      pr(f[i + 1][s ^ c]);
//                      prln(f[i][s]);
//                    }
                }
            }
        }
        ans += 1LL * (i + 1) * f[i + 1][0] % MOD;
        add(ans, 0);
    }
    printf("%d\n", ans);
    return 0;
}
