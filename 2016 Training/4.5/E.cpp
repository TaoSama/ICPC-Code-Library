//
//  Created by TaoSama on 2016-04-05
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
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

int n, a[N], b[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

	while(scanf("%d", &n) == 1){
		for(int i = 1; i <= n; ++i) scanf("%d", a + i);
		for(int i = 1; i <= n; ++i) scanf("%d", b + i);
		sort(a + 1, a + 1 + n);
		sort(b + 1, b + 1 + n);
		reverse(b + 1, b + 1 + n);

        long long ans = 0;
        for(int i = 1; i <= n; ++i) ans += a[i] * b[i];
        printf("%lld\n", ans);
	}
    return 0;
}