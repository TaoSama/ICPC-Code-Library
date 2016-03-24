//
//
//
//  Created by TaoSama on 2015-04-25
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

int n, q, c[N], ans;
vector<int> G[N];

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	int t; scanf("%d", &t);
	int kase = 0;
	while(t--){
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i) G[i].clear();
		memset(c, 0, sizeof c);
		for(int i = 1; i < n; ++i){
			int x, y; scanf("%d%d", &x, &y);
			G[x].push_back(y);
			G[y].push_back(x);
		}
		scanf("%d", &q);
		printf("Case #%d:\n", ++kase);
		ans = 1;
		while(q--){
			int x; scanf("%d", &x);
			if(x == 2){
				int y, color; scanf("%d%d", &y, &color);
				for(int i = 0; i < G[y].size(); ++i){
					int v = G[y][i];
					if(c[v] != color && c[v] == c[y]) ++ ans;
				}
				for(int i = 0; i < G[y].size(); ++i){
					int v = G[y][i];
					if(c[v] == color && c[v] != c[y]) --ans;
				}
				c[y] = color;
			}
			else{
				printf("%d\n", ans);
			}
		}
	}
	return 0;
}
