//
//  Created by TaoSama on 2016-05-05
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

int n, k;
int a[N], b[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &k) == 2) {
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);
        for(int i = 1; i <= n; ++i) scanf("%d", b + i);

        int ans = INF;
        for(int i = 1; i <= n; ++i)
            ans = min(ans, b[i] / a[i]);

        for(int i = 1; i <= n; ++i)
            b[i] -= ans * a[i];

//        prln(ans);
//        for(int i = 1; i <= n; ++i) printf("%d ", b[i]); puts("");

        int cnt = 0;
        while(k > 0) {
            pair<int, int> idx = {INF, -1};
            for(int i = 1; i <= n; ++i) {
                if(b[i] / a[i]) continue;
                idx = min(idx, {a[i] - b[i], i});
            }

            int delta = min(k, idx.first);
            b[idx.second] += delta;
            k -= delta;

//          pr(delta); pr(idx.second); prln(idx.first);
//          if(++cnt > 10) break;

            bool ok = true;
            for(int i = 1; i <= n; ++i)
                if(b[i] < a[i]) { ok = false; break;}
            if(ok) {
                for(int i = 1; i <= n; ++i) b[i] -= a[i];
                ++ans;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
