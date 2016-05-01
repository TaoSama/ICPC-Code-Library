//
//  Created by TaoSama on 2016-04-25
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

int n, a[N], mp[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        for(int i = 0; i <= n; ++i) scanf("%d", a + i);
        memset(mp, -1, sizeof mp);
        if(~n & 1) mp[0] = 0;

        long long ans = 0;
        for(int i = n; ~i; --i) {
            if(mp[i] == -1) {
                int b = 32 - __builtin_clz(i);
                int all = (1 << b) - 1;
                mp[i] = all ^ i;
                mp[all ^ i] = i;
            }
            ans += i ^ mp[i];
        }
        printf("%I64d\n", ans);
        for(int i = 0; i <= n; ++i)
            printf("%d%c", mp[a[i]], " \n"[i == n]);
    }
    return 0;
}
