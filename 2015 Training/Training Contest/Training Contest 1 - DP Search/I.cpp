//
//
//
//  Created by TaoSama on 2015-03-08
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

int s, n, m, vis[105][105];
struct Sta {
	int s, n, m, step;
	Sta(int s, int n, int m, int step = 0):
		s(s), n(n), m(m), step(step) {}
};

int bfs() {
	queue<Sta> q; q.push(Sta(s, 0, 0));
	memset(vis, 0, sizeof vis); vis[0][0] = true;
	while(!q.empty()) {
		Sta cur = q.front(); q.pop();
		if(cur.s == s >> 1 && cur.n == s >> 1) return cur.step;
//		printf("cur.s = %d, cur.n = %d, cur.m = %d, dp = %d\n",
//				cur.s,cur.n,cur.m,cur.step);
		Sta nxt = cur; ++nxt.step;
		if(nxt.s > 0 && nxt.n < n) {
			int t = min(nxt.s, n - nxt.n);
			nxt.s -= t; nxt.n += t;
			if(!vis[nxt.n][nxt.m]) q.push(nxt), vis[nxt.n][nxt.m] = true;
		}
		nxt = cur; ++nxt.step;
		if(nxt.s > 0 && nxt.m < m) {
			int t = min(nxt.s, m - nxt.m);
			nxt.s -= t; nxt.m += t;
			if(!vis[nxt.n][nxt.m]) q.push(nxt), vis[nxt.n][nxt.m] = true;
		}
		nxt = cur; ++nxt.step;
		if(nxt.n > 0 && nxt.m < m) {
			int t = min(nxt.n, m - nxt.m);
			nxt.n -= t; nxt.m += t;
			if(!vis[nxt.n][nxt.m]) q.push(nxt), vis[nxt.n][nxt.m] = true;
		}
		nxt = cur; ++nxt.step;
		if(nxt.n > 0 && nxt.s < s) {
			int t = min(nxt.n, s - nxt.s);
			nxt.n -= t; nxt.s += t;
			if(!vis[nxt.n][nxt.m]) q.push(nxt), vis[nxt.n][nxt.m] = true;
		}
		nxt = cur;  ++nxt.step;
		if(nxt.m > 0 && nxt.s < s) {
			int t = min(nxt.m, s - nxt.s);
			nxt.m -= t; nxt.s += t;
			if(!vis[nxt.n][nxt.m]) q.push(nxt), vis[nxt.n][nxt.m] = true;
		}
		nxt = cur;  ++nxt.step;
		if(nxt.m > 0 && nxt.n < n) {
			int t = min(nxt.m, n - nxt.n);
			nxt.m -= t; nxt.n += t;
			if(!vis[nxt.n][nxt.m]) q.push(nxt), vis[nxt.n][nxt.m] = true;
		}
	}
	return 0;
}

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	while(cin >> s >> n >> m && s && n && m) {
		if(n < m) swap(n, m);
		if(s & 1) cout << "NO" << endl;
		else {
			int ans = bfs();
			if(ans == 0) cout << "NO" << endl;
			else	cout << ans << endl;
		}
	}
	return 0;
}
