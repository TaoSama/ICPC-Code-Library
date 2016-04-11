//
//  Created by TaoSama on 2015-04-22
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

int L, n, m, a[50005];

bool check(int x) {
    int last = 0;
    //<=> 选出n-m个间距都>=x
    for(int i = 1; i <= n + 1 - m; ++i){
		int idx = last + 1;
		while(idx <= n + 1 && a[idx] - a[last] < x) ++idx;
		if(idx == n + 2) return false;
		last = idx;
    }
    return true;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    cin >> L >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    a[0] = 0; a[n + 1] = L;
    int l = 0, r = L + 1;
    while(l + 1 < r) {
        int mid = l + r >> 1;
        if(check(mid)) l = mid;
        else r = mid;
    }
    cout << l << '\n';
    return 0;
}
