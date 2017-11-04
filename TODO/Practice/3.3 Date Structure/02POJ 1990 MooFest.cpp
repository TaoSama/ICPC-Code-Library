//
//  Created by TaoSama on 2015-05-28
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

long long n, cnt[20005], dis[20005];
pair<int, int> cow[20005];

void add(long long* b, int i, int x) {
    for(; i <= 20000; i += i & -i)
        b[i] += x;
}

long long sum(long long* b, int i) {
    long long ret = 0;
    for(; i; i -= i & -i)
        ret += b[i];
    return ret;
}

long long sum(long long* b, int s, int g) {
    return sum(b, g) - sum(b, s - 1);
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
        scanf("%d%d", &cow[i].first, &cow[i].second);
    sort(cow + 1, cow + 1 + n);

    long long ans = 0;
    for(int i = 1; i <= n; ++i) {
        long long v = cow[i].first, x = cow[i].second;
        long long l = sum(cnt, 1, x - 1), r = sum(cnt, x + 1, 20000);
        ans += v * ((l * x - sum(dis, 1, x - 1)) + (sum(dis, x + 1, 20000) - r * x));
        add(cnt, x, 1);
        add(dis, x, x);
    }
    printf("%lld\n", ans);
    return 0;
}
