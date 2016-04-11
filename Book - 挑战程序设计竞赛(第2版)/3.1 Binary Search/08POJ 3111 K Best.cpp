//
//  Created by TaoSama on 2015-04-28
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

int n, k, v[N], w[N];
struct Jewel {
    int id;
    double y;
    bool operator<(const Jewel& rhs) const {
        return y > rhs.y;
    }
} a[N];

bool check(double x) {
    for(int i = 1; i <= n; ++i) {
        a[i].id = i;
        a[i].y = v[i] - x * w[i];
    }
    sort(a + 1, a + 1 + n);
    double sum = 0;
    for(int i = 1; i <= k; ++i) sum += a[i].y;
    return sum >= 0;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; ++i) scanf("%d%d", v + i, w + i);

    double l = 0, r = 1e7 + 1;
    for(int i = 0; i < 50; ++i) {
        double mid = (l + r) / 2;
        if(check(mid)) l = mid;
        else r = mid;
    }

    for(int i = 1; i <= k; ++i)
        printf("%d%c", a[i].id, i == k ? '\n' : ' ');
    return 0;
}
