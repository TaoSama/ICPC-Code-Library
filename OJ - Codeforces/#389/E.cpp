//
//  Created by TaoSama on 2016-12-25
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
const int N = 1e7 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, k;
typedef long long LL;
LL cnt[N], larger[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &k) == 2) {
        memset(cnt, 0, sizeof cnt);
        memset(larger, 0, sizeof larger);
        for(int i = 1; i <= n; ++i) {
            int x; scanf("%d", &x);
            ++cnt[x];
        }

        LL sum = 0;
        int ans = -1;
        for(int i = 1e7; i && !~ans; --i) {
            sum += cnt[i];
            sum -= larger[i];
            if(sum >= k) ans = i;
            cnt[i >> 1] += cnt[i];
            cnt[i + 1 >> 1] += cnt[i];
            larger[i + 1 >> 1] += cnt[i];
        }
        printf("%d\n", ans);
    }

    return 0;
}
