//
//  Created by TaoSama on 2016-05-06
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

struct SparseTable {
    int n, dp[20][N];
    void init(int _n, int* a) {
        n = _n;
        for(int i = 1; i <= n; ++i) dp[0][i] = a[i];
        for(int i = 1; (1 << i) <= n; ++i)
            for(int j = 1; j + (1 << i) - 1 <= n; ++j)
                dp[i][j] = max(dp[i - 1][j],
                               dp[i - 1][j + (1 << i - 1)]);
    }
    int RMQ(int l, int r) {
        int k = 31 - __builtin_clz(r - l + 1);
        return max(dp[k][l], dp[k][r - (1 << k) + 1]);
    }
} st;

int n, m;
int a[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d%d", &n, &m);
    memset(a, -1, sizeof a);
    for(int i = 1; i <= n; ++i) {
        int t, v; scanf("%d%d", &t, &v);
        a[t] = max(a[t], v);
    }
    st.init(n, a);
    while(m--) {
        int a, b; scanf("%d%d", &a, &b);
        int ans = st.RMQ(a, b);
        if(ans == -1) puts("None");
        else printf("%d\n", ans);
    }
    return 0;
}
