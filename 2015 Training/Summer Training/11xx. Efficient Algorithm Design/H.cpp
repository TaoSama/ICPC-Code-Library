//
//  Created by TaoSama on 2015-07-31
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
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, a[N], lef[N], rig[N], minv[N];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        lef[0] = rig[n - 1] = 1;
        for(int i = 0; i < n; ++i) {
            scanf("%d", a + i);
            if(i) {
                lef[i] = 1;
                if(a[i] > a[i - 1]) lef[i] += lef[i - 1];
            }
        }
        for(int i = n - 2; i >= 0; --i) {
            rig[i] = 1;
            if(a[i] < a[i + 1]) rig[i] += rig[i + 1];
        }

        int ans = 0;
        memset(minv, 0x3f, sizeof minv);
        for(int i = 0; i < n; ++i) {
            int l = lower_bound(minv + 1, minv + 1 + n, a[i]) - minv;
            ans = max(ans, rig[i] + l - 1);
            minv[lef[i]] = min(minv[lef[i]], a[i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}
