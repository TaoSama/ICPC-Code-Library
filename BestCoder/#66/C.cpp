//
//  Created by TaoSama on 2015-12-12
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

LL A, B, L, R;
int a[70], b[70], l[70], r[70], dp[70][4][4]; //0 for free

inline void add(int &x, int y) {
    if((x += y) >= MOD) x -= MOD;
}

int dfs(int p, int s1, int s2) {
    if(p < 0) return 1;
    int &ret = dp[p][s1][s2];
    if(ret >= 0) return ret;
    ret = 0;
    for(int i = 0; i < 2; ++i) {
        if(i < l[p] && (s1 & 1)) continue;
        if(i > r[p] && (s1 & 2)) continue;
        int ns1 = s1;
        if(i > l[p] && (ns1 & 1)) ns1 ^= 1; //set free
        if(i < r[p] && (ns1 & 2)) ns1 ^= 2;
        for(int j = 0; j < 2; ++j) {
            if(i ^ a[p] != j ^ b[p]) continue;
            if(j < l[p] && (s2 & 1)) continue;
            if(j > r[p] && (s2 & 2)) continue;
            int ns2 = s2;
            if(j > l[p] && (ns2 & 1)) ns2 ^= 1;
            if(j < r[p] && (ns2 & 2)) ns2 ^= 2;
            add(ret, dfs(p - 1, ns1, ns2));
        }
    }
    return ret;
}

void calc(LL A, int *a) {
    for(int i = 0; i < 64; ++i) a[i] = A >> i & 1;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%I64d%I64d%I64d%I64d", &L, &R, &A, &B);
        calc(L, l); calc(R, r);
        calc(A, a); calc(B, b);
        memset(dp, -1, sizeof dp);
        int ans = (R - L + 1) * 2 % MOD;
        ans -= dfs(63, 3, 3);
        if(ans < 0) ans += MOD;
        printf("%d\n", ans);
    }
    return 0;
}
