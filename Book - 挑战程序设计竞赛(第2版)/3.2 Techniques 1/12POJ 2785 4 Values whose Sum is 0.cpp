//
//  Created by TaoSama on 2015-12-22
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
const int N = 4e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, a[N], b[N], c[N], d[N];
int s[N * N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i)
            scanf("%d%d%d%d", a + i, b + i, c + i, d + i);
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                int idx = (i - 1) * n + j;
                s[idx] = c[i] + d[j];
            }
        }
        sort(s + 1, s + 1 + n * n);
        int ans = 0;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                pair<int*, int*> ret = equal_range(s + 1, s + 1 + n * n,
                                                   -(a[i] + b[j]));
                ans += ret.second - ret.first;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
