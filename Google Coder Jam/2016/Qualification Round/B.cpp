//
//
//  Created by TaoSama on 2016-04-09
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

char s[N];

int main() {
#ifdef LOCAL
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%s", s + 1);
        int n = strlen(s + 1);
        int ans = 0;
        for(int i = 1; i <= n; ++i) {
            int j = i;
            while(j + 1 <= n && s[j + 1] == s[i]) ++j;
            ++ans;
            i = j;
        }
        ans -= s[n] == '+';
        static int kase = 0;
        printf("Case #%d: %d\n", ++kase, ans);
    }
    return 0;
}
