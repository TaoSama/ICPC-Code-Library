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

int n, a[N];
long long half;

bool check(int x) {
	int cnt = 0;
	for(int i = 1; i <= n; ++i)
		cnt += a + n - lower_bound(a + 1, a + 1 + n, a[i] + x) + 1;
	return cnt > half;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);
        sort(a + 1, a + 1 + n);

		half = n * (n - 1LL) >> 2;
        int l = 0, r = 1e9;
        while(l + 1 < r) {
            int mid = l + r >> 1;
            if(check(mid)) l = mid;
            else r = mid;
        }
        printf("%d\n", l);
    }
    return 0;
}
