//
//  Created by TaoSama on 2016-02-29
//  Copyright (c) 2016 TaoSama. All rights reserved.
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

//period is lcm, then difference between 2 zeros is same
//     5: 0 1 2 3 4 0 1 2 3 4 0 1 2 3 4
//     3: 0 1 2 0 1 2 0 1 2 0 1 2 0 1 2
// |a-b|: 0 0 0 3 3 2 1 1 1 4 1 1 2 2 2

int n, a, b;
typedef long long LL;

LL get(int n) {
    LL ret = 0;
    int up = 0, down = 0, cur = 0;
    while(cur < n) {
        int dif = abs(up - down);
        int cnt = min(a - up, b - down);
        cnt = min(cnt, n - cur);
        ret += 1LL * cnt * dif;
        up = (up + cnt) % a;
        down = (down + cnt) % b;
//      printf("dif: %d cnt: %d up: %d down: %d\n", dif, cnt, up, down);
        cur += cnt;
    }
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d", &n, &a, &b);
        LL cycle = 1LL * a / __gcd(a, b) * b;
        LL ans = 1LL * (n / cycle) * get(cycle) + get(n % cycle);
        printf("%I64d\n", ans);
    }
    return 0;
}
