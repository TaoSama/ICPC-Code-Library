//
//  Created by TaoSama on 2017-04-08
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
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, k;
int f[N];
char s[N];

int main() {
#ifdef LOCAL
    freopen("A-large-practice.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%s%d", s + 1, &k);
        n = strlen(s + 1);

        int sum = 0, ans = 0;
        for(int i = 1; i + k - 1 <= n; ++i) {
            int x = s[i] == '-';
            f[i] = 0;
            if((sum + x) & 1) {
                ++ans;
                f[i] = 1;
            }
            sum += f[i];
            if(i + k - 1 >= 1) sum -= f[i - k + 1];
        }
        for(int i = n - k + 2; i <= n && ~ans; ++i) {
            int x = s[i] == '-';
            if((sum + x) & 1) ans = -1;
            if(i + k - 1 >= 1) sum -= f[i - k + 1];
        }

        static int kase = 0;
        printf("Case #%d: ", ++kase);
        if(ans == -1) puts("IMPOSSIBLE");
        else printf("%d\n", ans);
    }

    return 0;
}
