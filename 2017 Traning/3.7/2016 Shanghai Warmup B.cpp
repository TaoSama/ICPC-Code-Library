//
//  Created by TaoSama on 2016-12-10
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
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
int x[N], y[N], l[N], r[N];
int a, b, c1, c2, m;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d%d%d%d%d%d", &n, x + 1, y + 1, &a, &b, &c1, &c2, &m);
        for(int i = 2; i <= n; ++i) {
            x[i] = (1LL * a * x[i - 1] + 1LL * b * y[i - 1] + c1) % m;
            y[i] = (1LL * a * y[i - 1] + 1LL * b * x[i - 1] + c2) % m;
        }

        map<int, int> mp;
        for(int i = 1; i <= n; ++i) {
            l[i] = min(x[i], y[i]);
            r[i] = max(x[i], y[i]);
            ++mp[l[i]];
            --mp[r[i] + 1];
        }

        int last = mp.begin()->first, sum = 0;
        int tot = 0, maxv = 0;
        for(auto& p : mp) {
            if(sum) tot += p.first - last;
            if(sum == 1) maxv = max(maxv, p.first - last);
            last = p.first;
            sum += p.second;
        }

        static int kase = 0;
        printf("Case #%d: %d\n", ++kase, tot - maxv);
    }

    return 0;
}
