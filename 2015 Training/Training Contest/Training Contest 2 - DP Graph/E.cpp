//
//
//
//  Created by TaoSama on 2015-03-15
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
#define CLR(x,y) memset(x, y, sizeof(x))

using namespace std;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

int t, s, d, V, a[1005][1005], dp[1005];
typedef pair<int, int> P;

int dijkstra(int s, int g) {
	priority_queue<P, vector<P>, greater<P> > pq;
	memset(dp, 0x3f, sizeof dp); dp[s] = 0;
	pq.push(P(0, s));
	while(!pq.empty()) {
		P p = pq.top(); pq.pop();
		int cur = p.second;
		if(dp[cur] < p.first) continue;
		for(int i = 0; i <= V; ++i) {
			if(a[cur][i] != INF &&
			        dp[i] > dp[cur] + a[cur][i]) {
				dp[i] = dp[cur] + a[cur][i];
				pq.push(P(dp[i], i));
			}
		}
	}
	return dp[g];
}

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	while(cin >> t >> s >> d) {
		V = 0; memset(a, 0x3f, sizeof a);
		for(int i = 1; i <= t; ++i) {
			int x, y, v; cin >> x >> y >> v;
			a[x][y] = min(a[x][y], v);
			a[y][x] = min(a[y][x], v);
			V = max(V, max(x, y));
		}
		for(int i = 1; i <= s; ++i) {
			int st; cin >> st;
			a[0][st] = a[st][0] = 1;
		}
		++V;
		for(int i = 1; i <= d; ++i) {
			int ed; cin >> ed;
			a[ed][V] = a[V][ed] = 1;
		}

		cout << dijkstra(0, V) - 2 << endl;
	}
	return 0;
}
