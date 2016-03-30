//
//  Created by TaoSama on 2016-01-26
//  Copyright (c) 2015 TaoSama. All rights reserved.
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
const int N = 1e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;
int n, K; LL l;
pair<int, int> a[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%I64d%d", &n, &l, &K) == 3) {
        for(int i = 0; i < n; ++i) {
            scanf("%d", &a[i].first);
            a[i].second = i;
        }
        sort(a, a + n);

        vector<vector<int> > f(K, vector<int>(n));
        for(int i = 0; i < n; ++i) f[0][i] = 1;
        for(int i = 1; i < K; ++i) {
            int sum = 0;
            for(int j = 0, k = 0; j < n; ++j) {
                while(k < n && a[k].first <= a[j].first)
                    sum = (sum + f[i - 1][k++]) % MOD;
                f[i][j] = sum;
            }
        }
        LL ans = 0;
        for(int i = 0; i < K; ++i) {
            for(int j = 0; j < n; ++j) {
                LL cnt = l / n + (a[j].second < l % n);
                if(cnt - i > 0) {
                    ans += (cnt - i) % MOD * f[i][j] % MOD;
                    ans %= MOD;
                }
            }
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
