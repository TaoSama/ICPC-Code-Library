//
//  Created by TaoSama on 2015-08-21
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
const int N = 1e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, k;
int a[N], cnt[N];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
//    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    int kase = 0;
    while(t--) {
        scanf("%d%d%d", &n, &m, &k);
        a[1] = 1; a[2] = 2; a[3] = 3;
        for(int i = 4; i <= n; ++i) {
            a[i] = (a[i - 1] + a[i - 2] + a[i - 3]) % m + 1;
        }
//         for(int i = 1; i <= n; ++i)
//            printf("%3d%c", i, " \n"[i == n]);
//        for(int i = 1; i <= n; ++i)
//            printf("%3d%c", a[i], " \n"[i == n]);
        memset(cnt, 0, sizeof cnt);

        int ans = INF, num = 0;
        int l = 1, r = 1;
        while(r <= n) {
            if(cnt[a[r]]++ == 0) {
                if(a[r] >= 1 && a[r] <= k)++num;
            }
            r++;
            while(num == k) {
                ans = min(ans, r - l);
//                pr(l); pr(r); prln(num);
                if(--cnt[a[l]] == 0) {
                    if(a[l] >= 1 && a[l] <= k)--num;
                }
                l++;
            }
        }
        printf("Case %d: ", ++kase);
        if(ans == INF) puts("sequence nai");
        else printf("%d\n", ans);
    }
    return 0;
}
