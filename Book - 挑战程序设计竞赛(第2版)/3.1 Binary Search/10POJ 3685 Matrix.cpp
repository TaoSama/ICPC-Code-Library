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

long long n, m;

bool check(long long x) {
    long long cnt = 0;
    for(int j = 1; j <= n; ++j) {
        int l = 0, r = n + 1;
        while(l + 1 < r) {
            int i = l + r >> 1;
            long long col = 1LL * j * j + 1LL * i * i + 1LL * i * j + (i - j) * 100000LL;
            if(col < x) l = i;
            else r = i;
        }
        cnt += l;
    }
    return cnt < m;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) {
        cin >> n >> m;
        long long l = -100000 * n, r = 3 * n * n + 100000 * n;
        while(l + 1 < r) {
            long long mid = l + r >> 1;
            if(check(mid)) l = mid;
            else r = mid;
        }
        cout << l << '\n';
    }
    return 0;
}
