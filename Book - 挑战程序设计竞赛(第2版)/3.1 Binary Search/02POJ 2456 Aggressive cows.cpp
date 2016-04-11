//
//  Created by TaoSama on 2015-04-18
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

int n, c, a[N];

bool check(int x) {
	int last = 1;
	for(int i = 2; i <= c; ++i){
		int idx = last + 1;
		while(idx <= n && a[idx] - a[last] < x)
			idx++;
		if(idx == n + 1) return false;
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

    scanf("%d%d", &n, &c);
    for(int i = 1; i <= n; ++i) scanf("%d", a + i);
    sort(a + 1, a + 1 + n);
    int l = 0, r = 1e9 + 1;
    while(l + 1 < r) {
        int mid = 0LL + l + r >> 1;
        if(check(mid)) l = mid;
        else r = mid;
    }
    printf("%d\n", l);
    return 0;
}
