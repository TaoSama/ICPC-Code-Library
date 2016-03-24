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

string s, t;
typedef pair<string, int> Sta;
map<string, int> dp;
map<string, string> ans;

string getString(string s, int x) {
	if(x == 0) {
		reverse(s.begin(), s.end());
	} else if(x == 1) {
		char c1 = s[3], c2 = s[4];
		s.erase(3, 1); s = c1 + s;
		s.erase(4, 1); s.insert(7, 1, c2);
	} else {
		char c1 = s[1], c2 = s[2], c3 = s[5], c4 = s[6];
		s.replace(1, 1, 1, c4); s.replace(2, 1, 1, c1);
		s.replace(5, 1, 1, c2); s.replace(6, 1, 1, c3);
	}
	return s;
}
void bfs() {
	queue<string> q; dp.clear(); ans.clear();
	q.push("12345678"); dp["12345678"] = 0;
	while(!q.empty()) {
		string s = q.front(); q.pop();
		for(int i = 0; i < 4; ++i) {
			string ns = getString(s, i);
			if(!dp.count(ns) || dp[ns] > dp[s] + 1) {
				dp[ns] = dp[s] + 1;
				ans[ns] = ans[s] + (char)('A' + i);
				q.push(ns);
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
	while(cin >> s >> t) {
		char a[10];
		for(int i = 0; i < 8; ++i)
			a[s[i] - '0'] = '1' + i;
		for(int i = 0; i < 8; ++i)
			t[i] = a[t[i] - '0'];

		cout << ans[t] << endl;
	}
	return 0;
}
