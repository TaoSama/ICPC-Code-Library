//
//  Created by TaoSama on 2016-04-30
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

int n;
int r[N];
string a[N], b[N];

int main() {
#ifdef LOCAL
    freopen("C-small-practice.in", "r", stdin);
    freopen("C-small-practice.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) {
            char buf[50];
            scanf("%s", buf); a[i] = buf;
            scanf("%s", buf); b[i] = buf;
        }

        int ans = 0;
        set<string> f, g;
        for(int i = 1; i < 1 << n; ++i) {
            int fake = __builtin_popcount(i);
            if(fake <= ans) continue;

            f.clear(); g.clear();
            for(int j = 0; j < n; ++j) {
                if(!(i >> j & 1)) {
                    f.insert(a[j]);
                    g.insert(b[j]);
                }
            }

            bool ok = true;
            for(int j = 0; j < n; ++j) {
                if(i >> j & 1) {
                    //fake
                    if(f.count(a[j]) && g.count(b[j])) {}
                    else {
                        ok = false;
                        break;
                    }
                }
            }
            if(ok) ans = fake;
        }

        static int kase = 0;
        printf("Case #%d: %d\n", ++kase, ans);
    }
    return 0;
}
