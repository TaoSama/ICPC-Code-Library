//
//  Created by TaoSama on 2016-10-29
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

int n, k;
typedef long long LL;
LL a[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &k);
        LL sum = 0;
        for(int i = 1; i <= n; ++i) {
            scanf("%I64d", a + i);
            sum += a[i];
        }
        static int kase = 0;
        printf("Case #%d: ", ++kase);
        if(sum % k) {puts("-1"); continue;}

        LL avg = sum / k;
        LL ans = 0;
        for(int i = 1; i <= n; ++i) {
            if(a[i] == avg) continue;
            if(a[i] > avg) {
                LL num = a[i] / avg;
                ans += num - 1;
                a[i] %= avg;
                if(a[i]) --i;
            } else {
                LL two = a[i] + a[i + 1];
                if(two == 2 * avg) ++i;
                else if(two < 2 * avg) {
                    a[i + 1] = two;
                    ++i;
                } else {
                    a[i] = two - 2 * avg;
                }
                ++ans;
            }
//          pr(i); prln(ans);
        }
        printf("%I64d\n", ans);
    }

    return 0;
}
