//
//  Created by TaoSama on 2015-08-26
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
const int N = 1e7 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int p[N];
int find(int x) {
    return p[x] = p[x] == x ? x : find(p[x]);
}

bool unite(int x, int y) {
    x = find(x); y = find(y);
    if(x == y) return false;
    p[x] = y;
    return true;
}

int n, m;

long long ksm(long long x, long long n) {
    long long ret = 1;
    while(n) {
        if(n & 1) ret = ret * x % MOD;
        x = x * x % MOD;
        n >>= 1;
    }
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &m) == 2) {
        for(int i = 0; i <= n; ++i) p[i] = i;
        int cnt = n;
        for(int i = 1; i <= m; ++i) {
            int l, r; scanf("%d%d", &l, &r);
            cnt -= unite(l - 1, r);
        }
        printf("%d\n", ksm(26, cnt));
    }
    return 0;
}
