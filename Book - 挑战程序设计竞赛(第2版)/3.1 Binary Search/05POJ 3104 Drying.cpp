//
//  POJ 3104 Drying
//
//  Created by TaoSama on 2015-04-24
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
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
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

int n, k, a[N];

// k * x + (mid - x) >= a[i]  ==> x >= (a[i] - mid) / (k - 1)

bool check(int x) {
    int cnt = 0;
    for(int i = 1; i <= n; ++i) {
        if(a[i] > x)  cnt += (a[i] - x + k - 2) / (k - 1);
        if(cnt > x) return true;
    }
    return false;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        int ans = -INF;
        for(int i = 1; i <= n; ++i) {
            scanf("%d", a + i);
            ans = max(ans, a[i]);
        }
        scanf("%d", &k);
        if(k != 1) {
            int l = 0, r = ans + 1;
            while(l + 1 < r) {
                int mid = 0LL + l + r >> 1;
                if(check(mid)) l = mid;
                else r = mid;
            }
            ans = r;
        }
        printf("%d\n", ans);
    }
    return 0;
}
