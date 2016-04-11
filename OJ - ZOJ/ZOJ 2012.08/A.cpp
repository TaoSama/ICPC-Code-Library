//
//  Created by TaoSama on 2015-10-09
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
const int N = 5e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, q, a[N], l[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        map<int, int> mp;
        memset(l, 0, sizeof l);
        for(int i = 1; i <= n; ++i) {
            scanf("%d", a + i);
            l[i] = max(l[i], l[i - 1]);
            if(mp.count(a[i])) l[i] = max(l[i], mp[a[i]]);
            mp[a[i]] = i;
        }
        scanf("%d", &q);
        while(q--) {
            int x, y; scanf("%d%d", &x, &y);
            if(x > l[y]) puts("OK");
            else printf("%d\n", a[l[y]]);
        }
        puts("");
    }
    return 0;
}
