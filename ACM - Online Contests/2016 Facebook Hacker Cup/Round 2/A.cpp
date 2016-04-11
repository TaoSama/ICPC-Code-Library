//
//  Created by TaoSama on 2016-01-24
//  Copyright (c) 2015 TaoSama. All rights reserved.
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
char s[N], t[N];
int pre[N], suf[N];

int main() {
    freopen("boomerang_decoration.txt", "r", stdin);
    freopen("boomerang_decoration_out1.txt", "w", stdout);
    ios_base::sync_with_stdio(0);

    int T; scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        scanf("%s%s", s + 1, t + 1);
        pre[0] = suf[n + 1] = 0;
        for(int i = 1; i <= n; ++i)
            pre[i] = pre[i - 1] + (t[i] != t[i - 1]);
        for(int i = n; i; --i)
            suf[i] = suf[i + 1] + (t[i] != t[i + 1]);

//        for(int i = 0; i <= n + 1; ++i) printf("%3d", i); puts("");
//        for(int i = 0; i <= n + 1; ++i) printf("%3d", pre[i]); puts("");
//        for(int i = 0; i <= n + 1; ++i) printf("%3d", suf[i]); puts("");

        int ans = INF;
        for(int i = 1, j; i <= n; ++i) {
            if(s[i] != t[i]) {
                ans = min(ans, max(pre[i - 1], suf[i]));
                ans = min(ans, max(pre[i], suf[i + 1]));
            } else {
                for(j = i; j + 1 <= n && s[j + 1] == t[j + 1]; ++j);
                ans = min(ans, max(pre[i - 1], suf[j + 1]));
                i = j;
            }
        }

        static int kase = 0;
        printf("Case #%d: %d\n", ++kase, ans);
    }
    return 0;
}
