//
//  Created by TaoSama on 2015-10-03
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

int n, a[N], b[N];
bool vis[N];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);
        for(int i = 1; i <= n; ++i) {
            int x; scanf("%d", &x);
            b[a[i]] = x;
        }

        memset(vis, false, sizeof vis);
        int ans = 0;
        for(int i = 1; i <= n; ++i) {
            if(!vis[i]) {
                int j = i, cnt = 0;
                while(!vis[j]) {
                    ++cnt;
                    vis[j] = true;
                    j = b[j];
                }
                ans += max(1, cnt - 1);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
