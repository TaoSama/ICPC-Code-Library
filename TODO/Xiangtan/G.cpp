//
//  Created by TaoSama on 2017-05-16
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
typedef long long LL;

int n;
int l[N], c[N], d[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        LL ans = 0;
        for(int i = 1; i <= n; ++i) {
            char p[2]; scanf("%d%s%d", l + i, p, d + i);
            c[i] = *p == '(' ? 1 : -1;
            if(c[i] == 1) ans += 1LL * l[i] * d[i];
        }

        int sum = 0;
        set<pair<int, int>> s;
        for(int i = 1; i <= n; ++i) {
            sum -= l[i];
            s.insert({ -c[i] * d[i], i});
            while(sum < 0) {
                auto iter = s.begin();
                int can = min((-sum + 1) / 2, l[iter->second]);
                sum += 2 * can;
                l[iter->second] -= can;
                ans += 1LL * can * iter->first;
                if(l[iter->second] == 0) s.erase(iter);
            }
        }
        printf("%lld\n", ans);
    }


    return 0;
}
