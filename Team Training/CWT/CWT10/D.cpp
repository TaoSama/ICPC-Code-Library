//
//  Created by TaoSama on 2016-02-12
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
const int N = 1e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, k, m;

inline void add(int& x, int y) {
    if((x += y) >= m) x -= m;
}

int f[N][100][2], power[N];

int dfs(int i, int mod, bool ok, bool notSuf) {
    if(i == n) return ok;
    int& ret = f[i][mod][ok];
    if(~ret) return ret;
    ret = 0;
    for(int d = i == n - 1; d <= 9; ++d) {
        int nxtMod = (d * power[i] % k + mod) % k;
        int nxtOk = ok | (notSuf && d == 0 ? 0 : nxtMod == 0);
        add(ret, dfs(i + 1, nxtMod, nxtOk, notSuf && d == 0));
    }
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);



    while(scanf("%d%d%d", &n, &k, &m) == 3) {
        memset(f, -1, sizeof f);
        power[0] = 1;
        for(int i = 1; i <= n; ++i) power[i] = power[i - 1] * 10 % k;
        printf("%d\n", dfs(0, 0, 0, 1));
    }
    return 0;
}
