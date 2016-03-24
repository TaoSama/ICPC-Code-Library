//
//  Created by TaoSama on 2015-09-23
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
//#pragma comment(linker, "/STACK:1024000000,1024000000")
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

int n, k, ans;
bool cat[N];
vector<int> G[N];

void dfs(int u, int f, int c){
	if(c > k) return;
	int cnt = 0;
	for(auto v : G[u]){
		if(v == f) continue;
		++cnt;
		dfs(v, u, cat[v] ? c + 1 : 0);
	}
	if(cnt == 0) ++ans;
}

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	while(scanf("%d%d", &n, &k) == 2){
		for(int i = 1; i <= n; ++i) scanf("%d", cat + i);
		for(int i = 1; i <= n; ++i) G[i].clear();
		for(int i = 1; i < n; ++i){
			int u, v; scanf("%d%d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		ans = 0;
		dfs(1, -1, cat[1]);
		printf("%d\n", ans);
	}
	return 0;
}
