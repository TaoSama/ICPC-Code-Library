//
//
//
//  Created by TaoSama on 2015-04-05
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

int n, a[1 << 12], mp, ans = 0;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d", &n);
    for(int i = 2; i < (1 << (n + 1)); ++i) scanf("%d", &a[i]);
    int ans = 0;
    for(int i = (1 << n) - 1; i > 0; --i) {
        int t = max(a[i << 1], a[i << 1 | 1]);
        a[i] += t;
        ans += abs(a[i << 1] - a[i << 1 | 1]);
    }
    printf("%d\n", ans);
    return 0;
}
