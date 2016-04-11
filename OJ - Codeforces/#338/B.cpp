//
//  Created by TaoSama on 2016-01-08
//  Copyright (c) 2015 TaoSama. All rights reserved.
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

int n, m;
vector<int> G[N];

int f[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

	while(scanf("%d%d", &n, &m) == 2){
		for(int i = 1; i <= n; ++i) G[i].clear();
		for(int i = 1; i <= m; ++i){
			int u, v; scanf("%d%d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
        for(int i = 1; i <= n; ++i) f[i] = 1;
        for(int u = 1; u <= n; ++u)
			for(int v : G[u])
				if(v > u) f[v] = max(f[v], f[u] + 1);

		long long ans = 0;
		for(int i = 1; i <= n; ++i)
			ans = max(ans, 1LL * f[i] * G[i].size());
		printf("%I64d\n", ans);
	}
    return 0;
}
