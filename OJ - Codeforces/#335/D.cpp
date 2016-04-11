//
//  Created by TaoSama on 2015-12-10
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

int n, m, r[N], f[N];
pair<int, int> a[N], ans[N];

bool cmp(int x, int y) {
    return a[x] < a[y];
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &m) == 2) {
        for(int i = 1; i <= m; ++i) {
            scanf("%d%d", &a[i].first, &a[i].second);
            a[i].second ^= 1;
        }
        for(int i = 1; i <= m; ++i) r[i] = i;
        sort(r + 1, r + 1 + m, cmp);

        bool ok = true;
        for(int i = 1; i <= n; ++i) f[i] = i + 2;
        for(int i = 1, j = 1; i <= m; ++i) {
            int idx = r[i];
            if(a[idx].second ^ 1) {
                ans[idx] = make_pair(j, j + 1);
                ++j;
            } else {
                int u = 1;
                while(f[u] > j && u <= j) ++u;
                if(f[u] > j) {ok = false; break;}
                ans[idx] = make_pair(u, f[u]++);
            }
        }
        if(!ok) {puts("-1"); continue;}
        for(int i = 1; i <= m; ++i)
            printf("%d %d\n", ans[i].first, ans[i].second);
    }
    return 0;
}
