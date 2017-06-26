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

char s[N];

int main() {
#ifdef LOCAL
    freopen("B-large-practice.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%s", s + 1);
        int n = strlen(s + 1);

        bool ok = true;
        for(int i = 1; i + 1 <= n && ok; ++i) ok &= s[i] <= s[i + 1];

        int st = 1;
        if(!ok) {
            ok = true;
            for(int i = 2; i + 1 <= n; ++i) {
                if(ok && s[i] >= s[i - 1] + 1) st = i;
                ok &= s[i] >= s[i - 1];
            }
            --s[st];
            for(int i = st + 1; i <= n; ++i) s[i] = '9';

            st = 0;
            for(int i = 1; i <= n && !st; ++i) if(s[i] != '0') st = i;
        }
        static int kase = 0;
        printf("Case #%d: %s\n", ++kase, s + st);
    }

    return 0;
}
