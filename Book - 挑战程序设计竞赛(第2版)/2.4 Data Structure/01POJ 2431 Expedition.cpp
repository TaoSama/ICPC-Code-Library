//
//  POJ 2431 Expedition
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

int n;
pair<int, int> a[10005];

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	while(cin >> n) {
		priority_queue<int> pq;
		for(int i = 1; i <= n; ++i)
			cin >> a[i].first >> a[i].second;
		int l, p; cin >> l >> p;
		sort(a + 1, a + 1 + n);
		a[0].first = a[0].second = 0;
		int ans = 0;
		for(int i = n; i >= 0; --i) {
			while(p - l + a[i].first < 0) {
				if(pq.empty()) {
					ans = -1;
					break;
				}
				p += pq.top(); pq.pop();
				++ ans;
			}
			if(ans == -1) break;
			pq.push(a[i].second);
		}
		cout << ans << endl;
	}
	return 0;
}
