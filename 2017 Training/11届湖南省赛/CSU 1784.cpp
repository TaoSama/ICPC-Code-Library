//
//  Created by TaoSama on 2017-05-06
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 3e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, a, b;
typedef long long LL;
LL x[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d%d%d", &n, &m, &a, &b) == 4) {
        for(int i = 1; i <= m; ++i) {
            char s[100]; scanf("%s", s);
            x[i] = 0; int b = 0;
            for(int j = 0; s[j]; ++j) if(s[j] == '0' || s[j] == '1') s[b++] = s[j];
            for(int j = 0; j < b; ++j)
                if(s[j] == '1') x[i] |= 1LL << j;
            x[i] ^= x[i - 1];
        }

        LL ans = 0, tot = (1LL << n) - 1;
        map<LL, int> mp;
        for(int i = 1; i <= m; ++i) {
            if(i - a >= 0) ++mp[x[i - a]];
            ans += mp[tot ^ x[i]];
            if(i - b >= 0) --mp[x[i - b]];
        }
        static int kase = 0;
        printf("Case %d: %lld\n", ++kase, ans);
    }

    return 0;
}
