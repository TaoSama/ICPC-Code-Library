//
//  Created by TaoSama on 2015-08-24
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e8 + 7;

int n;

int b[N];
void add(int i, int x) {
    for(; i <= n; i += i & -i) b[i] += x;
}

int sum(int i) {
    int ret = 0;
    for(; i; i -= i & -i) ret += b[i];
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    int kase = 0;
    while(t--) {
        scanf("%d", &n);
        memset(b, 0, sizeof b);
        long long ans = 0;
        for(int i = 1; i <= n; ++i) {
            int x; scanf("%d", &x);
            int l = sum(x), r = (n - x) - (i - 1 - l);
            ans += 1LL * r * (r - 1) / 2 - 1LL * l * r;
            add(x, 1);
        }
        printf("Case #%d: %I64d\n", ++kase, ans % MOD);
    }
    return 0;
}
