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
const int N = 2e3 + 10;

int n, ans, alone[N];
int pnt[N], nxt[N], head[N], cnt;

void add_edge(int u, int v) {
	pnt[cnt] = v;      //cnt条边 u->v
	nxt[cnt] = head[u]; //cnt这条边 上一条 u->x 的位置
	head[u] = cnt++;    //更新head的位置
}

void dfs(int u, int dep) {
	ans = max(ans, dep);
	for(int i = head[u]; i != -1; i = nxt[i])
		dfs(pnt[i], dep + 1);
}

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	while(cin >> n) {
		cnt = 0;
		memset(head, -1, sizeof head);
		memset(nxt, -1, sizeof nxt);
		memset(alone, false, sizeof alone);
		for(int i = 1; i <= n; ++i) {
			int v; cin >> v;
			if(v == -1) alone[i] = true;
			else add_edge(v, i);
		}
		ans = -INF;
		for(int i = 1; i <= n; ++i)
			if(alone[i]) dfs(i, 1);
		cout << ans << endl;
	}
	return 0;
}
