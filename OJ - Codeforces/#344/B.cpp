//
//  Created by TaoSama on 2016-03-04
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

int n, m, k;
pair<int, int> r[N], c[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d%d", &n, &m, &k) == 3) {
        for(int i = 1; i <= n; ++i) r[i] = {0, 0};
        for(int i = 1; i <= m; ++i) c[i] = {0, 0};
        for(int i = 1; i <= k; ++i) {
            int op, x, y; scanf("%d%d%d", &op, &x, &y);
            if(op == 1) r[x] = {y, i};
            else c[x] = {y, i};
        }
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                int cur = r[i].second > c[j].second ? r[i].first : c[j].first;
                printf("%d%c", cur, " \n"[j == m]);
            }
        }
    }
    return 0;
}
