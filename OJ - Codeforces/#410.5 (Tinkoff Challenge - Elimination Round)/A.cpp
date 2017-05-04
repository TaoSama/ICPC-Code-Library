//
//  Created by TaoSama on 2017-04-24
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, k;
int a[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &k) == 2) {
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);

        int minv = *min_element(a + 1, a + 1 + n);

        long long ans = 0;
        for(int i = 1; i <= n && ~ans; ++i) {
            if((a[i] - minv) % k) ans = -1;
            else ans += (a[i] - minv) / k;
        }
        printf("%I64d\n", ans);
    }

    return 0;
}
