//
//  Created by TaoSama on 2015-05-27
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

int n, m, q, a[505][505], Max[505];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d%d%d", &n, &m, &q);
    for(int i = 1; i <= n; ++i) {
        int t = 0, ct = 0;
        for(int j = 1; j <= m; ++j) {
            scanf("%d", &a[i][j]);
            if(a[i][j]) {
                ++ct;
                t = max(t, ct);
            } else ct = 0;
        }
        Max[i] = t;
    }

    while(q--){
		int x, y; scanf("%d%d", &x, &y);
		a[x][y] = !a[x][y];
		int ct = 0, t = 0;
		for(int i = 1; i <= m; ++i){
			if(a[x][i]) {
                ++ct;
                t = max(t, ct);
            } else ct = 0;
		}
		Max[x] = t;
		printf("%d\n", *max_element(Max + 1, Max + 1 + n));
    }

    return 0;
}
