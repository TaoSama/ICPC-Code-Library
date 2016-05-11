//
//  Created by TaoSama on 2016-03-19
//  Copyright (c) 2016 TaoSama. All rights reserved.
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, k;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &k);
        if(1LL * k * (k + 1) >> 1 > n) {puts("-1"); continue;}
        int l = 1, r = n;
        while(l <= r) {
            int m = l + r >> 1;
            if(1LL * k * (m + m + k - 1) / 2 <= n) l = m + 1;
            else r = m - 1;
        }
        --l;
        int cnt = n - 1LL * k * (l + l + k - 1) / 2;
        r = l + k - 1;
        int ans = 1;
        while(r >= l) {
            ans = 1LL * ans * (r + (cnt > 0 ? 1 : 0)) % MOD;
            --r; --cnt;
        }
        printf("%d\n", ans);
    }
    return 0;
}
