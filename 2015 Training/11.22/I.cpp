//
//  Created by TaoSama on 2015-11-22
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

int n, m, a[25], wh[25], seat[25];
int u[25], v[25], c[25];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &m) == 2 && (n || m)) {
        for(int i = 1; i <= m; ++i) scanf("%d%d%d", u + i, v + i, c + i);
        int ans = 0;
        for(int i = 0; i < n; ++i) a[i] = i;
        do {
            for(int i = 0; i < n; ++i) wh[a[i]] = i;
            int ok = true;
            for(int i = 1; i <= m; ++i) {
                int dif = abs(wh[u[i]] - wh[v[i]]);
                if(c[i] > 0) {
                    if(dif > c[i]) {
                        ok = false;
                        break;
                    }
                } else {
                    if(dif < -c[i]) {
                        ok = false;
                        break;
                    }
                }
            }
            ans += ok;
        } while(next_permutation(a, a + n));
        printf("%d\n", ans);
    }
    return 0;
}
