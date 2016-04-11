//
//  AOJ 0121 Seven Puzzle
//
//  Created by TaoSama on 2015-02-20
//  Copyright (c) 2014 TaoSama. All rights reserved.
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

string s;
typedef pair<string, int> Sta;
map<string, int> dp;
int d[4] = { -1, 1, 4, -4};

void bfs() {
	queue<Sta> q;
	dp["01234567"] = 0; q.push(Sta("01234567", 0));
	while(!q.empty()) {
		string s = q.front().first;
		int cur = q.front().second;
		q.pop();
		for(int i = 0; i < 4; ++i) {
			string ns = s;
			int nxt = cur + d[i];
			if(nxt < 0 || nxt > 7 || cur == 3 && nxt == 4 || cur == 4 && nxt == 3)
				continue;
			swap(ns[cur], ns[nxt]);
			if(!dp.count(ns)) {
				dp[ns] = dp[s] + 1;
				q.push(Sta(ns, nxt));
			}
		}
	}
}
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	bfs();
	while(cin >> s) {
		for(int i = 1; i <= 7; ++i) {
			char x; cin >> x;
			s += x;
		}
		cout << dp[s] << endl;
	}
	return 0;
}
