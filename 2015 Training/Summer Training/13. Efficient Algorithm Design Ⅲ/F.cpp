//
//  Created by TaoSama on 2015-08-03
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

int n, L, D;
struct P {
    double l, r;
    bool operator< (const P& rhs) const {
        return r < rhs.r;
    }
} a[N];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &L, &D) == 2) {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) {
            int x, y; scanf("%d%d", &x, &y);
            double l = sqrt(D * D - y * y);
            a[i].l = x - l, a[i].r = x + l;
        }
        sort(a + 1, a + 1 + n);

        int ans = 0;
        double pre = -1e20;
        for(int i = 1; i <= n; ++i) {
            if(pre >= a[i].l && pre <= a[i].r) continue;
            if(pre < a[i].l) {
                ++ans;
                pre = a[i].r;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
