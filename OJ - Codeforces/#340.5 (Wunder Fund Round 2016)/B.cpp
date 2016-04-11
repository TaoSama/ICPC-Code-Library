//
//  Created by TaoSama on 2016-01-30
//  Copyright (c) 2015 TaoSama. All rights reserved.
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

int n, a[55][55], ans[55];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j) scanf("%d", &a[i][j]);
        for(int i = 1; i <= n; ++i) {
            set<int> s;
            for(int j = 1; j <= n; ++j) s.insert(a[i][j]);
            if(s.size() != n) continue;
            for(int j = 1; j <= n; ++j)
                ans[j] = a[i][j] ? a[i][j] : n;
            bool ok = true;
            for(int j = 1; j <= n; ++j) {
                for(int k = 1; k <= n; ++k) {
                    if(j == k) continue;
                    if(min(ans[j], ans[k]) != a[j][k]) {
                        ok = false;
                        break;
                    }
                }
                if(!ok) break;
            }
            if(ok) break;
        }
        for(int i = 1; i <= n; ++i) printf("%d%c", ans[i], " \n"[i == n]);
    }
    return 0;
}
