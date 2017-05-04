//
//  Created by TaoSama on 2017-04-10
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
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
int a[N][N], b[N][N];
int two[N * 2];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    two[0] = 1;
    for(int i = 1; i < 2 * N; ++i) two[i] = two[i - 1] * 2 % MOD;

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                scanf("%d", a[i] + j);

        for(int i = 1; i <= n; ++i) {
            vector<int> v(m);
            for(int j = 1; j <= m; ++j) v[j - 1] = a[i][j];
            sort(v.begin(), v.end());
            for(int j = 1; j <= m; ++j)
                b[i][j] = v.end() - upper_bound(v.begin(), v.end(), a[i][j]);
        }
        for(int j = 1; j <= m; ++j) {
            vector<int> v(n);
            for(int i = 1; i <= n; ++i) v[i - 1] = a[i][j];
            sort(v.begin(), v.end());
            for(int i = 1; i <= n; ++i)
                b[i][j] += lower_bound(v.begin(), v.end(), a[i][j]) - v.begin();
        }

        int ans = 0;
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                if((ans += two[b[i][j]]) >= MOD) ans -= MOD;

        printf("%d\n", ans);
    }

    return 0;
}
