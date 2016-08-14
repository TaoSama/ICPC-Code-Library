//
//  Created by TaoSama on 2016-08-11
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
const int S = 18;

int n;
int g[S][S];
int f[1 << S];
bool isI[1 << S];

typedef unsigned int UINT;

UINT ksm(UINT x, UINT n) {
    UINT ret = 1;
    for(; n; n >>= 1) {
        if(n & 1) ret = ret * x;
        x = x * x;
    }
    return ret;
}

int v[S];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                scanf("%1d", g[i] + j);

        for(int s = 0; s < 1 << n; ++s) {
            int cnt = 0;
            for(int u = 0; u < n; ++u)
                if(s >> u & 1) v[cnt++] = u;
            bool ok = true;
            for(int i = 0; i < cnt && ok; ++i)
                for(int j = i + 1; j < cnt && ok; ++j)
                    if(g[v[i]][v[j]]) ok = false;
            isI[s] = ok;
        }

        memset(f, 0x3f, sizeof f);
        f[0] = 0;
        for(int s = 1; s < 1 << n; ++s) {
            for(int s0 = s; s0; s0 = (s0 - 1) & s) {
                if(!isI[s0]) continue;
                f[s] = min(f[s], f[s ^ s0] + 1);
            }
        }

        UINT ans = 0, m233 = 1;
        for(int s = 1; s < 1 << n; ++s) {
            m233 *= 233;
            ans += f[s] * m233;
        }
        printf("%u\n", ans);
    }

    return 0;
}
