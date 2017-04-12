//
//  Created by TaoSama on 2017-04-13
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, a[N];
typedef long long LL;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);
        sort(a + 1, a + 1 + n);

        auto get = [&](int x)->LL {
            LL ret = 0;
            for(int i = 1; i <= n; ++i) {
                int p = a[i] / (x + 1), q = a[i] % (x + 1);
                if(q == 0) ret += p;
                else if(p >= x - q) ret += p + 1;
                else return 1e18;
            }
            return ret;
        };

        LL ans = 1e18;
        for(int i = 1; i * i <= a[1]; ++i) {
            ans = min(ans, get(i));
            ans = min(ans, get(a[1] / i));
            ans = min(ans, get(a[1] / i - 1));
        }
        printf("%lld\n", ans);
    }

    return 0;
}
