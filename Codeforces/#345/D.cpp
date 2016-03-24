//
//  Created by TaoSama on 2016-03-07
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:1024000000,1024000000")
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

int n, a, b, T;
int pre[N], suf[N];
char s[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d%d%d", &n, &a, &b, &T) == 4) {
        scanf("%s", s + 1);
        pre[1] = suf[n + 1] = 0;
        for(int i = 2; i <= n; ++i)
            pre[i] = pre[i - 1] + a + (s[i] == 'w' ? b : 0) + 1;
        for(int i = n; i; --i)
            suf[i] = suf[i + 1] + a + (s[i] == 'w' ? b : 0) + 1;
        reverse(suf + 1, suf + 1 + n);

        int first = (s[1] == 'w' ? b : 0) + 1;
        int ans = first <= T;
        for(int i = 2; i <= n; ++i) {
            if(pre[i] + first > T) break;
            int leave = T - pre[i] - first - (i - 1) * a;
            int can = upper_bound(suf + 1, suf + 1 + n, leave) - suf - 1;
            ans = max(ans, i + can);
        }
        for(int i = 1; i <= n; ++i) {
            if(suf[i] + first > T) break;
            int leave = T - suf[i] - first - i * a;
            int can = upper_bound(pre + 2, pre + 1 + n, leave) - pre - 2;
            ans = max(ans, i + can + 1);
        }
        ans = min(ans, n);
        printf("%d\n", ans);
    }
    return 0;
}
