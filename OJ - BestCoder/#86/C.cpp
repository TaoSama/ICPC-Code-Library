//
//  Created by TaoSama on 2016-08-06
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
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, k, a[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d", &n, &m, &k);
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);
        long long ans = 0;
        int cnt = 0;
        for(int l = 1, r = 1; l <= n; ++l) {
            while(r <= n && cnt < k) {
                if(a[r] >= m) ++cnt;
                ++r;
            }
            if(cnt == k) ans += n - r + 2;
            if(a[l] >= m) --cnt;
        }
        printf("%I64d\n", ans);
    }

    return 0;
}
