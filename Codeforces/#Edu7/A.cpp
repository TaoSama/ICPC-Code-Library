//
//  Created by TaoSama on 2016-02-10
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

typedef long long LL;
LL n;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

	while(cin >> n){
		LL l = 1, r = 1e10;
		while(l <= r){
			LL m = l + r >> 1;
			if((1 + m) * m / 2 <= n) l = m + 1;
			else r = m - 1;
		}
		--l;
		LL ans = n - (1 + l) * l / 2;
        if(!ans) ans = l;
        cout << ans << '\n';
	}
    return 0;
}
