//
//  POJ 3614 Sunscreen
//
//  Created by TaoSama on 2015-03-13
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
pair<int, int> cow[2505], b[2505];

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	while(cin >> n >> m) {
		for(int i = 1; i <= n; ++i) cin >> cow[i].first >> cow[i].second;
		for(int i = 1; i <= m; ++i) cin >> b[i].first >> b[i].second;
		sort(cow + 1, cow + 1 + n); sort(b + 1, b + 1 + m);

		priority_queue<int, vector<int>, greater<int> > pq;
		int ans = 0, j = 1;
		for(int i = 1; i <= m; ++i) {
			while(j <= n && cow[j].first <= b[i].first) {
				pq.push(cow[j].second);
				++j;
			}
			while(!pq.empty() && b[i].second) {
				int MinSPF = pq.top(); pq.pop();
				if(MinSPF >= b[i].first)
					++ans, --b[i].second;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
