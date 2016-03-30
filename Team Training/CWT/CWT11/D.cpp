//
//  Created by TaoSama on 2016-02-21
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
const int N = 2e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, d;
char a[N], b[N], *p;

void add(int& x, int y) {
    if((x += y) >= MOD) x -= MOD;
}

int f[N][N];

int dfs(int i, int mod, int e) {
    if(i == n + 1) return !mod;
    if(!e && ~f[i][mod]) return f[i][mod];
    int ret = 0, to = e ? p[i] : 9;
    for(int x = 0; x <= to; ++x) {
        if(i & 1) {
            if(x == d) continue;
            add(ret, dfs(i + 1, (mod * 10 + x) % m, e && x == to));
        } else {
            if(x != d) continue;
            add(ret, dfs(i + 1, (mod * 10 + x) % m, e && x == to));
        }
    }
    return e ? ret : f[i][mod] = ret;
}

bool test() {
    int mod = 0;
    for(int i = 1; i <= n; ++i) {
        mod = (mod * 10 + a[i]) % m;
        if(i & 1) {
            if(a[i] == d) return false;
        } else {
            if(a[i] != d) return false;
        }
    }
    return !mod;
}

int calc(char *a) {
    p = a;
    return dfs(1, 0, 1);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d%s%s", &m, &d, a + 1, b + 1) == 4) {
        memset(f, -1, sizeof f);
        n = strlen(a + 1);
        for(int i = 1; a[i]; ++i) a[i] -= '0';
        for(int i = 1; b[i]; ++i) b[i] -= '0';
        int ans = calc(b);
        add(ans, MOD - calc(a) + test());
//      printf("%d %d\n", calc(a), calc(b));
        printf("%d\n", ans);
    }
    return 0;
}
