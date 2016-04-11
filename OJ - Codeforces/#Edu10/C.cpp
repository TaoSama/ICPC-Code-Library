//
//  Created by TaoSama on 2016-03-25
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
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
const int N = 3e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
int a[N], wh[N];
vector<int> qs[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &m) == 2) {
        for(int i = 1; i <= n; ++i) {
            scanf("%d", a + i);
            wh[a[i]] = i;
        }
        for(int i = 1; i <= n; ++i) qs[i].clear();
        for(int i = 1; i <= m; ++i) {
            int x, y; scanf("%d%d", &x, &y);
            x = wh[x]; y = wh[y];
            if(x > y) swap(x, y);
            qs[y].push_back(x);
        }

        long long ans = 0;
        int l = 0;
        for(int i = 1; i <= n; ++i) {
            for(int x : qs[i]) l = max(l, x);
            ans += l;
        }
        ans = 1LL * n * (n + 1) / 2 - ans;
        printf("%I64d\n", ans);
    }
    return 0;
}
