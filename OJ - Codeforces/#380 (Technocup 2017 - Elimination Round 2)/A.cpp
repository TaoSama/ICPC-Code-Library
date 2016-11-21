//
//  Created by TaoSama on 2016-11-20
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
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, k, s, t;
int c[N], v[N];
int g[N];

bool check(int tank) {
    int sum = 0;
    for(int i = 1; i <= k; ++i) {
        int dis = g[i] - g[i - 1];
        if(tank >= 2 * dis) {
            sum += dis;
        } else if(tank < dis) {
            return false;
        } else {
            int quick = tank - dis, slow = dis - quick;
            sum += quick + 2 * slow;
        }
        if(sum > t) return false;
    }
    return true;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d%d%d", &n, &k, &s, &t) == 4) {
        for(int i = 1; i <= n; ++i) scanf("%d%d", c + i, v + i);
        for(int i = 1; i <= k; ++i) scanf("%d", g + i);
        sort(g + 1, g + 1 + k);
        g[++k] = s;

        int l = 1, r = 1e9, tank = INF;
        while(l <= r) {
            int m = l + r >> 1;
            if(check(m)) tank = m, r = m - 1;
            else l = m + 1;
        }
        int ans = INF;
        for(int i = 1; i <= n; ++i) {
            if(v[i] >= tank) ans = min(ans, c[i]);
        }
        if(ans == INF) ans = -1;
        printf("%d\n", ans);
    }

    return 0;
}
