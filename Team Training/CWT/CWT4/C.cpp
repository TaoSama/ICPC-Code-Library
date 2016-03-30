//
//  Created by TaoSama on 2016-01-23
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
const int N = 5e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, a[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);
        int ans = 0; //do not concern last bit
        for(int i = 1, s, e; i < n; i = e) {
            //find cross start [s, e)
            for(s = i; s + 1 <= n; ++s)
                if(a[s + 1] != a[s]) break;

            int one = 0, zero = 0;
            //find cross end
            for(e = s + 1; e < n; ++e) {
                if(a[e] == a[e - 1]) break;
                if(a[e]) ++one;
                else ++zero;
            }
//          printf(": %d %d\n", s, e);
            for(int j = s, k = e; j <= k; ++j, --k) {
                a[j] = a[s];
                a[k] = a[e];
                if(j == k) a[j] = a[e];
            }
            if(a[e]) ans = max(ans, zero);
            else ans = max(ans, one);
        }
        printf("%d\n", ans);
        for(int i = 1; i <= n; ++i) printf("%d%c", a[i], " \n"[i == n]);
    }
    return 0;
}
