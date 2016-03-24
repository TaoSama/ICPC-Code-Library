//
//
//
//  Created by TaoSama on 2015-03-02
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

int n, m;
int dp[N];

int bfs() {
	memset(dp, 0x3f, sizeof dp);
	queue<int> q; q.push(n); dp[n] = 0;
	while(!q.empty()) {
		int cur = q.front(); q.pop();
		int nxt = cur - 1;
		if(nxt > 0 && nxt < 20001 && dp[nxt] > dp[cur] + 1) {
			dp[nxt] = dp[cur] + 1;
			//printf("dp[%d]: %d\n", nxt, dp[nxt]);
			q.push(nxt);
		}
		nxt = cur * 2;
		if(nxt > 0 && nxt < 20001 && dp[nxt] > dp[cur] + 1) {
			dp[nxt] = dp[cur] + 1;
			//printf("dp[%d]: %d\n", nxt, dp[nxt]);
			q.push(nxt);
		}
	}
	return dp[m];
}

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	while(cin >> n >> m) {
		cout << bfs() << endl;
	}
	return 0;
}
