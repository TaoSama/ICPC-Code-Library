
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;

int n, m, q[N];
LL sum[N], sq[N], cnt[N];
LL f[25][N];
LL up(int p, int k, int j) {
    return (2 * f[p][j] + sq[j] + j) - (2 * f[p][k] + sq[k] + k);
}
LL dw(int k, int j) {
    return j - k;
}
bool check(int p, int k, int j, int i) {
    return up(p, k, j) * dw(j, i) >= up(p, j, i) * dw(k, j);
}
    

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    while(scanf("%d%d", &n, &m) == 2) {
        memset(cnt, 0, sizeof cnt);
        for(int i = 1; i <= n; ++i) {
            int x; scanf("%d", &x);
            sq[i] = sq[i - 1];
            sq[i] -= cnt[x] * cnt[x];
            ++cnt[x];
            sq[i] += cnt[x] * cnt[x];
        }
        for(int j = 2; j <= m; ++j) {
            int L = 0, R = 0;
            q[R++] = 0;
            for(int i = 1; i <= n; ++i) {
                while(L + 1 < R && up(j - 1, q[L], q[L + 1]) <=
                        i * dw(q[L], q[L + 1])) ++L;
                int k = q[L];
                f[j][i] = f[j - 1][k] + 0; 
                while(L + 1 < R && check(j - 1, q[R - 2], q[R - 1], i)) --R;
                q[R++] = i;
            }
        }
        printf("%.12f\n", f[m][n]);
    }
    return 0;
}
