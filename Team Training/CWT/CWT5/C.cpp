//
//  Created by TaoSama on 2016-01-26
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
const int N = 2e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, a[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        memset(a, 0, sizeof a);
        for(int i = 1; i <= n; ++i) {
            int x; scanf("%d", &x);
            ++a[x];
        }

        int ans = 0;
        for(int i = 0; ; ++i) {
            if(i > 1e6 && !a[i]) break;
            a[i + 1] += a[i] / 2;
            ans += a[i] & 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}
