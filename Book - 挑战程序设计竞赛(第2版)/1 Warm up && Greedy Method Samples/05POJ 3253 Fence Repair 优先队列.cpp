//
//  POJ 3253 Fence Repair
//
//  Created by TaoSama on 2015-02-16
//  Copyright (c) 2014 TaoSama. All rights reserved.
//
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
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

int n;

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	while(cin >> n) {
		priority_queue<int, vector<int>, greater<int> > pq;
		for(int i = 1; i <= n; ++i) {
			int x; cin >> x;
			pq.push(x);
		}
		long long ans = 0;
		while(pq.size() > 1) {
			int s = pq.top(); pq.pop();
			s += pq.top(); pq.pop();
			ans += s; pq.push(s);
		}
		cout << ans << endl;
	}
	return 0;
}
