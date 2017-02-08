//
//  Created by TaoSama on 2017-01-31
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
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, l, r;
int a[N], b[N], p[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d%d", &n, &l, &r) == 3) {
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);
        vector<pair<int, int>> v;
        for(int i = 1; i <= n; ++i) {
            scanf("%d", p + i);
            v.push_back({p[i], i});
        }
        sort(v.begin(), v.end());

        int c = -INF;
        bool ok = true;  //c=b-a;
        for(int i = 0; i < v.size() && ok; ++i) {
            int p = v[i].second;
            b[p] = c + a[p];
            b[p] = max(b[p], l);
            b[p] = min(b[p], r);
            int nc = b[p] - a[p];
//            pr(p); pr(b[p]); pr(a[p]); pr(c); prln(nc);
            if(nc >= c) c = nc + 1;
            else ok = false;
        }
        if(ok) {
            for(int i = 1; i <= n; ++i) printf("%d%c", b[i], " \n"[i == n]);
        } else puts("-1");
    }

    return 0;
}
