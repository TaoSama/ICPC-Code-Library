//
//  Created by TaoSama on 2015-10-22
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
//#pragma comment(linker, "/STACK:1024000000,1024000000")
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

typedef long long LL;

struct Node {
    LL cnt, sum, sq;
    Node(int x = -1) {cnt = sum = sq = x;}
};

Node dp[20][7][7];
LL p[20], digit[20];

Node dfs(int i, int mod, int sum, int e) {
    Node &f = dp[i][mod][sum], suf, ret(0);
    if(!i) {
        ret.cnt = mod && sum;
        return ret;
    }
    if(!e && ~f.cnt) return f;
    int to = e ? digit[i] : 9;
    for(int d = 0; d <= to; ++d) {
        if(d == 7) continue;
        suf = dfs(i - 1, (mod * 10 + d) % 7, (sum + d) % 7, e && d == to);
        LL ten = p[i - 1];
        ret.cnt = (ret.cnt + suf.cnt) % MOD;
        LL b = d * ten % MOD, bsq = b * b % MOD;
        ret.sum = (ret.sum + b * suf.cnt % MOD + suf.sum) % MOD;
        ret.sq = (ret.sq + suf.cnt * bsq % MOD + 2 * b * suf.sum % MOD + suf.sq) % MOD;
    }
    return e ? ret : f = ret;
}

LL calc(LL x) {
    int cnt = 0;
    for(; x; x /= 10) digit[++cnt] = x % 10;
    return dfs(cnt, 0, 0, 1).sq;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    p[0] = 1;
    for(int i = 1; i < 20; ++i) p[i] = p[i - 1] * 10 % MOD;
    while(t--) {
        LL l, r; scanf("%I64d%I64d", &l, &r);
        printf("%I64d\n", (calc(r) - calc(l - 1) + MOD) % MOD);
    }
    return 0;
}
