//
//  Created by TaoSama on 2015-12-08
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

typedef unsigned long long ULL;
typedef pair<ULL, ULL> P;

int n;
P a[N];
ULL s[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    int kase = 0;
    while(t--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i)
            scanf("%llu%llu", &a[i].first, &a[i].second);
        sort(a + 1, a + 1 + n);

        ULL sum = 0;
        for(int i = 1; i <= n; ++i) {
            s[i] = s[i - 1] + a[i].second;
            sum += s[i] * a[i].second;
        }
        ULL cnt = 1;
        for(int i = n - 1; i; --i) cnt = cnt * (a[i].second + 1) % MOD;
        printf("Case %d: %llu %llu\n", ++kase, sum, cnt);
    }
    return 0;
}
