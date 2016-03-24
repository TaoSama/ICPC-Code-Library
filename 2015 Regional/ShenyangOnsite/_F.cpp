//
//  Created by TaoSama on 2015-10-31
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;

int n, m, a[N];

int phi(int n) {
    int ret = n, t = n;
    for(int i = 2; i * i <= n; i++) {
        if(t % i == 0) {
            ret = ret / i * (i - 1);
            while(t % i == 0) t /= i;
        }
    }
    if(t > 1) ret = ret / t * (t - 1);
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    int kase = 0;
    while(t--) {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; ++i) {
            int x; scanf("%d", &x);
            a[i] = __gcd(x, m);
        }
        vector<int> div;
        for(int i = 1; i * i <= m; ++i) {
            if(m % i == 0) {
                div.push_back(i);
                if(i * i != m) div.push_back(m / i);
            }
        }
        sort(a + 1, a + 1 + n);
        n = unique(a + 1, a + 1 + n) - a - 1;
        LL ans = 0;
        for(LL x : div) {
            for(int i = 1; i <= n; ++i) {
                if(x % a[i] == 0) {
                    ans += 1LL * m * phi(m / x) / 2;
                    break;
                }
            }
        }
        printf("Case #%d: %I64d\n", ++kase, ans);
    }
    return 0;
}
