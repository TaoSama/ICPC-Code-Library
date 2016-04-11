//
//  Created by TaoSama on 2015-11-25
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

int n;
int maxv[20][N], minv[20][N];

struct SparseTable {
    void init() {
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &maxv[0][i]);
            minv[0][i] = maxv[0][i];
        }
        for(int i = 1; (1 << i) <= n; ++i)
            for(int j = 1; j + (1 << i) - 1 <= n; ++j) {
                maxv[i][j] = max(maxv[i - 1][j],
                                 maxv[i - 1][j + (1 << i - 1)]);
                minv[i][j] = min(minv[i - 1][j],
                                 minv[i - 1][j + (1 << i - 1)]);
            }
    }
    int RMQ(int l, int r) {
        int k = 31 - __builtin_clz(r - l + 1);
        return max(maxv[k][l], maxv[k][r - (1 << k) + 1]) -
               min(minv[k][l], minv[k][r - (1 << k) + 1]);
    }
} st;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        st.init();
        int ans = 1;
        for(int i = 1; i + ans <= n; ++i) {
//          printf("%d %d\n", i, i + ans);
            while(i + ans <= n && st.RMQ(i, i + ans) <= 1) ++ans;
        }
        printf("%d\n", ans);
    }
    return 0;
}
