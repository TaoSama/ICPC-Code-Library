//
//  Created by TaoSama on 2017-04-22
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;
int n;

LL f[10][60];
int digit[10];
void toHex(int* s, LL x) {
    for(int i = 8; i; --i, x >>= 4) s[i] = x & 15;
}

int cost[] = {
    6, 2, 5, 5, 4, 5, 6, 3, 7, 6, 6, 5, 4, 5, 5, 4
};

LL dfs(int i, int s, int e) {
    if(i == 9) return s;
    if(!e && ~f[i][s]) return f[i][s];
    LL ret = 0;
    int to = e ? digit[i] : 15;
    for(int d = 0; d <= to; ++d) {
        ret += dfs(i + 1, s + cost[d], e && d == to);
    }
    return e ? ret : f[i][s] = ret;
}

LL calc(LL x) {
    toHex(digit, x);
    return dfs(1, 0, 1);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    memset(f, -1, sizeof f);

    const LL MAX = 0xffffffffLL;
    while(t--) {
        LL s; scanf("%lld%llX", &n, &s);
        LL to = 0LL + s + n - 1;
        LL ans = 0;
        if(to > MAX) {
            ans = calc(MAX) - calc(s - 1);
            ans += calc(to - MAX - 1);
        } else {
            ans = calc(to) - (s ? calc(s - 1) : 0);
        }
        printf("%lld\n", ans);
    }

    return 0;
}
